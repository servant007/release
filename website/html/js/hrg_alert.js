"use strict";var ALERT=ALERT||{info:function(t){var n=t.title||"default title",e=t.text||"default text";swal({title:n,text:e,imageUrl:"image/info_information.png",showCancelButton:!1,confirmButtonColor:"#3b6dde",confirmButtonText:"确认",closeOnConfirm:!1})},warn:function(t){var n=t.title||"default title",e=t.text||"default text";swal({title:n,text:e,imageUrl:"image/warning_information.png",showCancelButton:!1,confirmButtonColor:"#3b6dde",confirmButtonText:"确认",closeOnConfirm:!1})},error:function(t){var n=t.title||"default title",e=t.text||"default text";swal({title:n,text:e,imageUrl:"image/error_information.png",showCancelButton:!1,confirmButtonColor:"#3b6dde",confirmButtonText:"确认",closeOnConfirm:!1})},confirm:function(t){var n=t.title||"default title",e=t.text||"default text";swal({title:n,text:e,imageUrl:"image/warning_information.png",showCancelButton:!0,confirmButtonColor:"#3b6dde",cancelButtonText:"否",confirmButtonText:"是",closeOnConfirm:!0},function(){t.callback()})}};