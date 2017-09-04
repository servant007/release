"use strict";function toBinary(s,o){for(var o=o||16,r=parseInt(s).toString(2),t=o-r.length,c=[],f=0;f<t;f++)c.push(0);return r=c.join("")+r}var EXT=EXT||{PLC_STATUS:{CONVERTING:-1,ERROR_RUNNING:0,ERROR_STOP:1,RUNNING:10,STOP:11},turnOn:function(){console.log("[INFO]turn on plc");var s=NAV.waypointUserPubTopic(),o=new ROSLIB.Message({data:"relay_on"});s.publish(o),setTimeout(function(){o.data="relay_reset",s.publish(o)},1500)},turnOff:function(){console.log("[INFO]turn off plc");var s=NAV.waypointUserPubTopic(),o=new ROSLIB.Message({data:"relay_off"});s.publish(o),setTimeout(function(){o.data="relay_reset",s.publish(o)},1500)},plcStatusHandle:function(s){if(s!==EXT.PLC_STATUS.CONVERTING)switch(parseInt(toBinary(s).substr(14,2))){case EXT.PLC_STATUS.STOP:$("#extensions_start").css("backgroundColor","#3B6DDE").css("color","#ffffff").css("border",0),$("#extensions_stop").css("backgroundColor","#3B6DDE").css("color","#ffffff").css("border",0);break;case EXT.PLC_STATUS.RUNNING:$("#extensions_start").css("backgroundColor","#ffffff").css("color","#3B6DDE").css("border","1px solid #3B6DDE"),$("#extensions_stop").css("backgroundColor","#3B6DDE").css("color","#ffffff").css("border",0);break;case EXT.PLC_STATUS.ERROR_STOP:$("#extensions_start").css("backgroundColor","#3B6DDE").css("color","#ffffff").css("border",0),$("#extensions_stop").css("backgroundColor","#ff0000").css("color","#ffffff").css("border",0);break;case EXT.PLC_STATUS.ERROR_RUNNING:$("#extensions_start").css("backgroundColor","#ff0000").css("color","#ffffff").css("border",0),$("#extensions_stop").css("backgroundColor","#3B6DDE").css("color","#ffffff").css("border",0)}}};$(function(){$("#extensions_start").on("click",function(){DATA.plcStatus!==EXT.PLC_STATUS.CONVERTING&&DATA.plcStatus!==EXT.PLC_STATUS.RUNNING&&DATA.plcStatus!==EXT.PLC_STATUS.ERROR_RUNNING&&(EXT.turnOn(),DATA.plcStatus=EXT.PLC_STATUS.CONVERTING,$("#extensions_start").css("backgroundColor","#ffffff").css("color","#3B6DDE").css("border","1px solid #3B6DDE"))}),$("#extensions_stop").on("click",function(){DATA.plcStatus!==EXT.PLC_STATUS.CONVERTING&&DATA.plcStatus!==EXT.PLC_STATUS.STOP&&DATA.plcStatus!==EXT.PLC_STATUS.ERROR_STOP&&(EXT.turnOff(),DATA.plcStatus=EXT.PLC_STATUS.CONVERTING,$("#extensions_stop").css("backgroundColor","#ffffff").css("color","#3B6DDE").css("border","1px solid #3B6DDE"))})});