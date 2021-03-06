; Auto-generated. Do not edit!


(cl:in-package qr_navigation-msg)


;//! \htmlinclude qrMsg.msg.html

(cl:defclass <qrMsg> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass qrMsg (<qrMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <qrMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'qrMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name qr_navigation-msg:<qrMsg> is deprecated: use qr_navigation-msg:qrMsg instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <qrMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader qr_navigation-msg:header-val is deprecated.  Use qr_navigation-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <qrMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader qr_navigation-msg:name-val is deprecated.  Use qr_navigation-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <qrMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader qr_navigation-msg:id-val is deprecated.  Use qr_navigation-msg:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <qrMsg>) ostream)
  "Serializes a message object of type '<qrMsg>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <qrMsg>) istream)
  "Deserializes a message object of type '<qrMsg>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<qrMsg>)))
  "Returns string type for a message object of type '<qrMsg>"
  "qr_navigation/qrMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'qrMsg)))
  "Returns string type for a message object of type 'qrMsg"
  "qr_navigation/qrMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<qrMsg>)))
  "Returns md5sum for a message object of type '<qrMsg>"
  "e29cd348083eeece3acb349d73ceb1cf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'qrMsg)))
  "Returns md5sum for a message object of type 'qrMsg"
  "e29cd348083eeece3acb349d73ceb1cf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<qrMsg>)))
  "Returns full string definition for message of type '<qrMsg>"
  (cl:format cl:nil "Header header~%string name~%int32 id~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'qrMsg)))
  "Returns full string definition for message of type 'qrMsg"
  (cl:format cl:nil "Header header~%string name~%int32 id~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <qrMsg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'name))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <qrMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'qrMsg
    (cl:cons ':header (header msg))
    (cl:cons ':name (name msg))
    (cl:cons ':id (id msg))
))
