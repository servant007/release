"use strict";function getRobotModel(){var e="http://"+window.location.hostname+":8808/api/model";$.ajax({type:"get",url:e,async:!0,success:function(e){DATA.robotModel=e.model,console.log("[INFO]robot model: "+e.model)},dataType:"json"})}function getVersion(){var e="http://"+window.location.hostname+":8808/api/version";$.ajax({type:"get",url:e,async:!0,success:function(e){DATA.softwareVersion=e.version,console.log("[INFO]software version: "+e.version)},dataType:"json"})}function getBrowserInfo(){var e=navigator.userAgent.toLowerCase(),t=(e.match(/firefox|chrome|safari|opera/g)||"other")[0];(e.match(/msie|trident/g)||[])[0]&&(t="msie");var a="",o="",n="";switch(a="ontouchstart"in window||-1!==e.indexOf("touch")||-1!==e.indexOf("mobile")?-1!==e.indexOf("ipad")?"pad":-1!==e.indexOf("mobile")?"mobile":-1!==e.indexOf("android")?"androidPad":"pc":"pc",t){case"chrome":case"safari":case"mobile":o="webkit";break;case"msie":o="ms";break;case"firefox":o="Moz";break;case"opera":o="O";break;default:o="webkit"}n=e.indexOf("android")>0?"android":navigator.platform.toLowerCase();var i={version:(e.match(/[\s\S]+(?:rv|it|ra|ie)[\/: ]([\d.]+)/)||[])[1],plat:n,type:t,pc:a,prefix:o,isMobile:"pc"!=a};DATA.browserInfo=i}function initStage(e,t){var t=t||25,a=window.innerWidth||document.body.clientWidth||document.documentElement.clientWidth,o=window.innerHeight||document.body.clientHeight||document.documentElement.clientHeight,n=(e=e||{width:a,height:o}).width/e.height,i=a,s=o;a>o?(i=o*n,s=o):(i=a,s=a/n);var r=document.createElement("canvas");r.width=i,r.height=s,$("#mapNavDiv").append(r);var l=new createjs.Stage(r);DATA.register("stage",{stage:l,width:i,height:s},{}),createjs.Touch.enable(l),createjs.Ticker.setFPS(t),createjs.Ticker.addEventListener("tick",function(){l.update()})}function checkStr(e){return/^[^@\/\'\\\"\‘\’#$%&\^\*]+$/.test(e)}function isEqual(e,t){var a=e.substr(0,e.length-2);return(a=parseInt(a))===t}function main(){DATA.register("robotModel",null,{fnSet:UI.robotModelHandle}),DATA.register("softwareVersion",null,{fnSet:UI.softwareVersionHandle}),DATA.register("browserInfo",null,{fnSet:UI.browserInfoHandle}),DATA.register("ros",null,{}),DATA.register("topic",{},{}),DATA.register("mapMsg",null,{fnSet:UI.dispMap}),DATA.register("mapStage",null,{}),DATA.register("mapScaleStage",null,{}),DATA.register("waypointsMsg",null,{fnSet:UI.dispWaypoints}),DATA.register("waypointsStage",null,{}),DATA.register("trajectoriesMsg",null,{fnSet:UI.dispTrajectories}),DATA.register("robotPoseMsg",null,{fnSet:UI.dispRobot}),DATA.register("robotPoseStage",null,{}),DATA.register("globalPlanMsg",null,{fnSet:UI.dispGlobalPlan}),DATA.register("globalPlanStage",null,{}),DATA.register("localPlanMsg",null,{fnSet:UI.dispLocalPlan}),DATA.register("localPlanStage",null,{}),DATA.register("footprintMsg",null,{fnSet:UI.dispFootprint}),DATA.register("footprintStage",null,{}),DATA.register("tfMsg",{},{}),DATA.register("laserScanMsg",null,{fnSet:UI.dispLaserScan}),DATA.register("laserScanStage",null,{}),DATA.register("display",null,{fnSet:UI.display}),DATA.register("mapList",null,{fnSet:UI.updateMapList}),DATA.register("rosMode",null,{fnSet:UI.rosModeHandle}),DATA.register("mappingStatus",null,{}),DATA.register("brushStatus",null,{fnSet:UI.brushStatusHandle}),DATA.register("mapEditStageList",[],{}),DATA.register("mapEditObstacleList",[],{}),DATA.register("navCtrlStatus",null,{fnSet:UI.navCtrlStatusHandle}),DATA.register("selectedWaypoints",[],{}),DATA.register("dockInitPoseName",null,{}),DATA.register("powerStatus",null,{fnSet:UI.updatePowerStatus}),DATA.register("chargeStatus",null,{fnSet:UI.updateChargeStatus}),DATA.register("loading",null,{fnSet:UI.loading}),DATA.register("lastNetworkSetting",null,{fnSet:NET.lastNetworkSettingHandle}),DATA.register("powerAlarm",null,{}),DATA.register("plcStatus",null,{fnSet:EXT.plcStatusHandle}),DATA.register("diagnosticsMsg",null,{fnSet:UI.diagnosticsMsgHandle}),getBrowserInfo(),getRobotModel(),getVersion(),initStage(),DATA.loading="载入中";var e="ws://"+window.location.hostname+":9090";NAV.init(e),DEBUG.init(e),NAV.getRobotStatus(),NAV.listenTf(),NAV.dispMapAndWps("/map"),NAV.dispTrajectories(),NAV.dispRobot(),NAV.dispGlobalPlan(),NAV.dispLocalPlan(),NAV.dispFootprint(),NAV.dispLaserScan(),NAV.subShellFeedback(),NAV.subDiagnostics(),NAV.subMappingStatus(),NAV.pubCmdString(NAV.CmdEnum.MapSelect),NAV.subNavCtrlStatus(),NAV.subRobotStatus(),NAV.subLastNetworkSetting(),NAV.subWaypointUserSub()}$(function(){main();var e={disp_map:$("#disp-map").val(),disp_robotPose:$("#disp-robotPose").val(),disp_laserScan:$("#disp-laserScan").val(),disp_globalPlan:$("#disp-globalPlan").val(),disp_localPlan:$("#disp-localPlan").val(),disp_footprint:$("#disp-footprint").val()};for(var t in e){var a=t.split("_")[1],o="true"===e[t];DATA.display={property:a,value:o}}$("#disp-map").on("change",function(){DATA.display={property:"map",value:"true"===$("#disp-map").val()}}),$("#disp-robotPose").on("change",function(){DATA.display={property:"robotPose",value:"true"===$("#disp-robotPose").val()}}),$("#disp-footprint").on("change",function(){DATA.display={property:"footprint",value:"true"===$("#disp-footprint").val()}}),$("#disp-laserScan").on("change",function(){DATA.display={property:"laserScan",value:"true"===$("#disp-laserScan").val()}}),$("#disp-globalPlan").on("change",function(){DATA.display={property:"globalPlan",value:"true"===$("#disp-globalPlan").val()}}),$("#disp-localPlan").on("change",function(){DATA.display={property:"localPlan",value:"true"===$("#disp-localPlan").val()}}),$("#disp-waypoints").on("change",function(){DATA.display={property:"waypoints",value:"true"===$("#disp-waypoints").val()}}),$("#currentMapName").on("click",function(){var e=$(".map_nav");if(DATA.rosMode===NAV.RosMode.Navigation)if(isEqual(e.css("height"),35)){var t=35*(DATA.mapList.length+1);e.css("height",t)}else e.css("height","35px");else DATA.rosMode===NAV.RosMode.Gmapping&&(clickFeedback($("#currentMapName")),DATA.mappingStatus===NAV.CmdEnum.Gmapping?(console.log("[INFO]Save map"),NAV.saveMap(),$("#currentMapName").text("保存中"),DATA.loading="保存中"):DATA.mappingStatus===NAV.CmdEnum.SaveMap||(DATA.mappingStatus,NAV.CmdEnum.SaveMapEdit))}),$(".map_nav").mouseleave(function(){$(".map_nav").css("height","35px")}),$("#sidebar_site_span").on("click",function(){if(clickFeedback($("#sidebar_site_span")),DATA.waypointsMsg){var e=$(".sidebar_site"),t=e.css("height");isEqual(t,60)?(t=60*(DATA.waypointsMsg.waypoints.length+2),e.css("height",t),$("#sidebar_site_span").text("站点 ↑")):(e.css("height","60px"),$("#sidebar_site_span").text("站点 ↓"))}else ALERT.error({title:"站点错误",text:"站点不可用"})}),$("#sidebar_route_span").on("click",function(){if(clickFeedback($("#sidebar_route_span")),DATA.trajectoriesMsg){var e=$(".sidebar_route"),t=$("#sidebar_route_span");if(isEqual(e.css("height"),60)){var a=60*(DATA.trajectoriesMsg.trajectories.length+2);e.css("height",a),t.text("轨迹 ↑")}else e.css("height",60),t.text("轨迹 ↓")}else ALERT.error({title:"轨迹错误",text:"轨迹不可用"})}),$("#startMapping").on("click",function(){if(clickFeedback($("#startMapping")),DATA.rosMode===NAV.CmdEnum.Navigation){var e=$("#mapping_div_input").val();if(e===DATA.mapList[0])console.log("[INFO]Start mapping"),NAV.pubCmdString(NAV.CmdEnum.Gmapping),DATA.loading="切换中";else{if(!checkStr(e))return void ALERT.warn({title:"参数错误",text:"无效的地图名称"});NAV.manipulateScene(NAV.CmdEnum.MapInsert,e)}}}),$("#zoomIn").on("click",function(){DATA.brushStatus="zoomIn"}),$("#zoomOut").on("click",function(){DATA.brushStatus="zoomOut"}),$("#move").on("click",function(){DATA.brushStatus="move"}),$("#pencilTool").on("click",function(){DATA.brushStatus="pencilTool"}),$("#point").on("click",function(){DATA.brushStatus="point"}),$("#line").on("click",function(){DATA.brushStatus="line"}),$("#circle").on("click",function(){DATA.brushStatus="circle"}),$("#rect").on("click",function(){DATA.brushStatus="rect"}),$("#rubber").on("click",function(){DATA.brushStatus="rubber"}),$("#undo").on("click",function(){DATA.brushStatus="undo"}),$("#redo").on("click",function(){DATA.brushStatus="redo"}),$("#confirm").on("click",function(){DATA.brushStatus="confirm"}),$("#pose_estimate").on("click",function(){UI.poseEstimate()}),$("#wpType").on("change",function(){var e=$("#wpType").val(),t='<option value="LOOP">多次</option>\n                        <option value="NONE">单次</option>',a={height:0,overflow:"hidden"};if("sound_play"===e)t='<option value="START">播放</option>\n                        <option value="STOP">停止</option>\n                        <option value="ONCE">播放一次</option>';else if("goto"===e){t="";for(var o=0;o<DATA.waypointsMsg.waypoints.length;o++){var n=DATA.waypointsMsg.waypoints[o],i=n.name.split("_").slice(1).join("_");i||(i=n.name),t+='<option value="'+n.name+'">'+i+"</option>"}}else"pubsuber"===e&&(a={height:75,overflow:"none"});$("#wpMode").children().remove(),$("#wpMode").append(t),$("#pubsuber_expect_li").css("height",a.height),$("#pubsuber_expect_li").css("overflow",a.overflow)}),$("#wp_add_submit").on("click",function(){var e=$("#wpType").val();if(""!==e){var t;t="goto"===e?"looper":"dock"===e?"initial_pose":e;var a=$("#close_enough").val();a=parseFloat(a);var o=$("#timeout").val();o=parseFloat(o);var n=$("#wpMode").val();"pubsuber"===t&&(n=$("#pubsuber_expect").val());var i=$("#wpName").val();if(checkStr(i)){var s={frame_id:t,close_enough:a,goal_timeout:o,failure_mode:n,name:i=NAV.WaypointPrefix[t]+"_"+i,pose:DATA.robotPoseMsg};if(NAV.addWaypoint(s),console.log("[INFO]waypoint added"),"dock"===e){DATA.dockInitPoseName=i,s.frame_id="map",s.failure_mode="LOOP",s.name=NAV.DockingBegin[0];var r=TF.getDockingBeginPose(s.pose,PARAMS.DockingBeginDis);s.pose=r,NAV.addWaypoint(s),NAV.addWaypointsForDock(),NAV.addTrajForDock(),console.log("[INFO]docking begin waypoint added"),DATA.loading={key:"addDock",info:"保存中"}}}else ALERT.error({title:"参数错误",text:"站点名称不合法"})}else ALERT.error({title:"参数错误",text:"请选择站点类型"})}),$("#dock").on("click",function(){var e=$("#dock").attr("checked");DATA.isDock=!1,"checked"===e&&(DATA.isDock=!0),console.log(DATA.isDock)}),$("#waypointTrajAdd").on("change",function(){var e=$("#waypointTrajAdd").val();""===e&&ALERT.error({title:"参数错误",text:"请至少选择一个站点"}),DATA.selectedWaypoints.push(e),UI.dispSelectedWaypoints(),$("#waypointTrajAdd").val("")}),$("#traj_add_submit").on("click",function(){var e=$("#trajName").val();checkStr(e)?DATA.selectedWaypoints?(DATA.isDock&&(e="dock_"+e),NAV.addTrajectory(e,DATA.selectedWaypoints),$(".selectedWp").remove(),DATA.selectedWaypoints=[]):ALERT.error({title:"参数错误",text:"请选择站点"}):ALERT.error({title:"参数错误",text:"轨迹名称不合法"})}),$(".stop").on("click",function(){clickFeedback($(".stop")),NAV.navCtrl("",0)}),$(".direction_box_top").on("touchstart touchend click mouseleave",function(e){switch(e.type){case"touchstart":case"click":e.preventDefault(),$(".direction_box_top").css("background-image","url(../image/top_click.png)"),NAV.manualCtrl({linear:NAV.ManualCtrlVel.linear});break;case"touchend":case"mouseleave":$(".direction_box_top").css("background-image","url(../image/top.png)"),NAV.manualCtrl({})}}),$(".direction_box_bottom").on("touchstart touchend click mouseleave",function(e){switch(e.type){case"touchstart":case"click":e.preventDefault(),$(".direction_box_bottom").css("background-image","url(../image/bottom_click.png)"),NAV.manualCtrl({linear:-NAV.ManualCtrlVel.linear});break;case"touchend":case"mouseleave":$(".direction_box_bottom").css("background-image","url(../image/bottom.png)"),NAV.manualCtrl({})}}),$(".direction_box_left").on("touchstart touchend click mouseleave",function(e){switch(e.type){case"touchstart":case"click":e.preventDefault(),$(".direction_box_left").css("background-image","url(../image/left_click.png)"),NAV.manualCtrl({angular:NAV.ManualCtrlVel.angular});break;case"touchend":case"mouseleave":$(".direction_box_left").css("background-image","url(../image/left.png)"),NAV.manualCtrl({})}}),$(".direction_box_right").on("touchstart touchend click mouseleave",function(e){switch(e.type){case"touchstart":case"click":e.preventDefault(),$(".direction_box_right").css("background-image","url(../image/right_click.png)"),NAV.manualCtrl({angular:-NAV.ManualCtrlVel.angular});break;case"touchend":case"mouseleave":$(".direction_box_right").css("background-image","url(../image/right.png)"),NAV.manualCtrl({})}}),$(".direction_box_center").on("touchstart touchend click mouseleave",function(e){switch(e.type){case"touchstart":case"click":e.preventDefault(),$(".direction_box_center").css("background","#3b6dde"),NAV.manualCtrl({});break;case"touchend":case"mouseleave":$(".direction_box_center").css("background","#3b6dde")}})});