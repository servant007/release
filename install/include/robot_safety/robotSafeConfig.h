//#line 2 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the robot_safety package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __robot_safety__ROBOTSAFECONFIG_H__
#define __robot_safety__ROBOTSAFECONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace robot_safety
{
  class robotSafeConfigStatics;
  
  class robotSafeConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(robotSafeConfig &config, const robotSafeConfig &max, const robotSafeConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const robotSafeConfig &config1, const robotSafeConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, robotSafeConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const robotSafeConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, robotSafeConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const robotSafeConfig &config) const = 0;
      virtual void getValue(const robotSafeConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T robotSafeConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (robotSafeConfig::* field);

      virtual void clamp(robotSafeConfig &config, const robotSafeConfig &max, const robotSafeConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const robotSafeConfig &config1, const robotSafeConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, robotSafeConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const robotSafeConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, robotSafeConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const robotSafeConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const robotSafeConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, robotSafeConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, robotSafeConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<robotSafeConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(robotSafeConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("outer_major_radius"==(*_i)->name){outer_major_radius = boost::any_cast<double>(val);}
        if("outer_minor_radius"==(*_i)->name){outer_minor_radius = boost::any_cast<double>(val);}
        if("inner_base_radius"==(*_i)->name){inner_base_radius = boost::any_cast<double>(val);}
        if("inner_major_radius"==(*_i)->name){inner_major_radius = boost::any_cast<double>(val);}
        if("inner_minor_radius"==(*_i)->name){inner_minor_radius = boost::any_cast<double>(val);}
        if("restore_defaults"==(*_i)->name){restore_defaults = boost::any_cast<bool>(val);}
      }
    }

    double outer_major_radius;
double outer_minor_radius;
double inner_base_radius;
double inner_major_radius;
double inner_minor_radius;
bool restore_defaults;

    bool state;
    std::string name;

    
}groups;



//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double outer_major_radius;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double outer_minor_radius;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double inner_base_radius;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double inner_major_radius;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double inner_minor_radius;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool restore_defaults;
//#line 218 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("robotSafeConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const robotSafeConfig &__max__ = __getMax__();
      const robotSafeConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const robotSafeConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const robotSafeConfig &__getDefault__();
    static const robotSafeConfig &__getMax__();
    static const robotSafeConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const robotSafeConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void robotSafeConfig::ParamDescription<std::string>::clamp(robotSafeConfig &config, const robotSafeConfig &max, const robotSafeConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class robotSafeConfigStatics
  {
    friend class robotSafeConfig;
    
    robotSafeConfigStatics()
    {
robotSafeConfig::GroupDescription<robotSafeConfig::DEFAULT, robotSafeConfig> Default("Default", "", 0, 0, true, &robotSafeConfig::groups);
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.outer_major_radius = 0.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.outer_major_radius = 20.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.outer_major_radius = 0.7;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("outer_major_radius", "double", 0, "The major radius of the outer ellipse", "", &robotSafeConfig::outer_major_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("outer_major_radius", "double", 0, "The major radius of the outer ellipse", "", &robotSafeConfig::outer_major_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.outer_minor_radius = 0.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.outer_minor_radius = 20.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.outer_minor_radius = 0.3;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("outer_minor_radius", "double", 0, "The minor radius of the outer ellipse", "", &robotSafeConfig::outer_minor_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("outer_minor_radius", "double", 0, "The minor radius of the outer ellipse", "", &robotSafeConfig::outer_minor_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.inner_base_radius = 0.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.inner_base_radius = 20.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.inner_base_radius = 0.4;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("inner_base_radius", "double", 0, "The base radius of the robot", "", &robotSafeConfig::inner_base_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("inner_base_radius", "double", 0, "The base radius of the robot", "", &robotSafeConfig::inner_base_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.inner_major_radius = 0.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.inner_major_radius = 20.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.inner_major_radius = 0.6;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("inner_major_radius", "double", 0, "The major radius of the inner ellipse", "", &robotSafeConfig::inner_major_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("inner_major_radius", "double", 0, "The major radius of the inner ellipse", "", &robotSafeConfig::inner_major_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.inner_minor_radius = 0.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.inner_minor_radius = 20.0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.inner_minor_radius = 0.25;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("inner_minor_radius", "double", 0, "The minor radius of the inner ellipse", "", &robotSafeConfig::inner_minor_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<double>("inner_minor_radius", "double", 0, "The minor radius of the inner ellipse", "", &robotSafeConfig::inner_minor_radius)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.restore_defaults = 0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.restore_defaults = 1;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.restore_defaults = 0;
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<bool>("restore_defaults", "bool", 0, "Retsore the default configuration", "", &robotSafeConfig::restore_defaults)));
//#line 293 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(robotSafeConfig::AbstractParamDescriptionConstPtr(new robotSafeConfig::ParamDescription<bool>("restore_defaults", "bool", 0, "Retsore the default configuration", "", &robotSafeConfig::restore_defaults)));
//#line 246 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(robotSafeConfig::AbstractGroupDescriptionConstPtr(new robotSafeConfig::GroupDescription<robotSafeConfig::DEFAULT, robotSafeConfig>(Default)));
//#line 356 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<robotSafeConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<robotSafeConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<robotSafeConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    robotSafeConfig __max__;
    robotSafeConfig __min__;
    robotSafeConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const robotSafeConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static robotSafeConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &robotSafeConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const robotSafeConfig &robotSafeConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const robotSafeConfig &robotSafeConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const robotSafeConfig &robotSafeConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<robotSafeConfig::AbstractParamDescriptionConstPtr> &robotSafeConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<robotSafeConfig::AbstractGroupDescriptionConstPtr> &robotSafeConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const robotSafeConfigStatics *robotSafeConfig::__get_statics__()
  {
    const static robotSafeConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = robotSafeConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __ROBOTSAFERECONFIGURATOR_H__
