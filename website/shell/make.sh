#!/bin/bash

# ouiyeah @ 2018-02-22

while getopts "t:g:fizh" ARG; do
    case $ARG in
    t)
        typeset -l MAKE_TYPE=$OPTARG;
        ;;
    g)
        typeset -l MAKE_GENERATOR=$OPTARG;
        if [[ $MAKE_GENERATOR == eclipse ]]; then
            MAKE_G=" -G\"Eclipse CDT4 - Unix Makefiles\"";
        fi
        ;;
    f)
        MAKE_FORCE=" --force-cmake"
        ;;
    i)
        MAKE_INSTALL=" install";
        ;;
    z)
        COMPRESS_ZIP="enabled";
        ;;
    ?)
        echo "make.sh usage:";
        echo -e "\t-t\tbuild type (default for release)";
        echo -e "\t-g\tgenerator type (e.g. eclipse)";
        echo -e "\t-f\tforce cmake enabled";
        echo -e "\t-i\tmake install enabled";
        echo -e "\t-z\tcompress zip enabled";
        exit 1;
        ;;
    esac
done

if [[ ! $MAKE_TYPE ]]; then
    MAKE_TYPE="release";
fi
MAKE_EXPRESS=`echo $MAKE_TYPE | perl -pe 's/.*/\u$&/'`;
MAKE_EXPRESS=$MAKE_FORCE$MAKE_G" -DCMAKE_BUILD_TYPE="$MAKE_EXPRESS$MAKE_INSTALL;
cd ~/catkin_ws;
catkin_make $MAKE_EXPRESS;

if [[ $MAKE_INSTALL ]] && [ -L website ]; then
    mv -f website/shell/ tmp/;
    rm -r website/*;
    cp -r www/* website/;

    cd tmp;
    for SHELL_FILE in ../www/shell/*; do
        SHELL_FILE=${SHELL_FILE##*/};
        if [ -f $SHELL_FILE ]; then
            find $SHELL_FILE -newer ../www/shell/$SHELL_FILE | xargs -i rm ../website/shell/{};
        fi
    done
    cd ..;
    cd website/shell;
    ls | grep .sh$ | xargs -i shc -rTvf {};
    ls | grep .sh.x$ | awk -F '.' '{print $1}' | xargs -i mv -f {}.sh.x {}.sh;
    rm -f *.sh.x.c;
    cd ../..;
    for SHELL_FILE in tmp/*; do
        SHELL_FILE=${SHELL_FILE##*/};
        if [ -f www/shell/$SHELL_FILE ]; then
            if [ ! -f website/shell/$SHELL_FILE ]; then
                mv tmp/$SHELL_FILE website/shell/$SHELL_FILE;
            fi
        fi
    done
    rm -r tmp;
    cp -f www/shell/base.sh website/shell/base.sh; # TODO: temp used

    cd website/node;
    grunt;
    cd ../..;

    if [[ $COMPRESS_ZIP ]]; then
        cd ~/workspaces/hitrobot; mv release release-$ROS_DISTRO; zip -yr release-$ROS_DISTRO.zip release-$ROS_DISTRO; mv release-$ROS_DISTRO release;
        cd ~/catkin_ws/www/node/; zip -yr node_modules.zip node_modules/.; mv node_modules.zip ~/workspaces/hitrobot/;
    fi
fi
