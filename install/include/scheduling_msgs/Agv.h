// Generated by gencpp from file scheduling_msgs/Agv.msg
// DO NOT EDIT!


#ifndef SCHEDULING_MSGS_MESSAGE_AGV_H
#define SCHEDULING_MSGS_MESSAGE_AGV_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>

namespace scheduling_msgs
{
template <class ContainerAllocator>
struct Agv_
{
  typedef Agv_<ContainerAllocator> Type;

  Agv_()
    : agvID(0)
    , agvName()
    , isWorking(false)
    , isAgvBoot(false)
    , errorInfo(0)
    , working_station_name()
    , pose()  {
    }
  Agv_(const ContainerAllocator& _alloc)
    : agvID(0)
    , agvName(_alloc)
    , isWorking(false)
    , isAgvBoot(false)
    , errorInfo(0)
    , working_station_name(_alloc)
    , pose(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _agvID_type;
  _agvID_type agvID;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _agvName_type;
  _agvName_type agvName;

   typedef uint8_t _isWorking_type;
  _isWorking_type isWorking;

   typedef uint8_t _isAgvBoot_type;
  _isAgvBoot_type isAgvBoot;

   typedef int32_t _errorInfo_type;
  _errorInfo_type errorInfo;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _working_station_name_type;
  _working_station_name_type working_station_name;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;




  typedef boost::shared_ptr< ::scheduling_msgs::Agv_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::scheduling_msgs::Agv_<ContainerAllocator> const> ConstPtr;

}; // struct Agv_

typedef ::scheduling_msgs::Agv_<std::allocator<void> > Agv;

typedef boost::shared_ptr< ::scheduling_msgs::Agv > AgvPtr;
typedef boost::shared_ptr< ::scheduling_msgs::Agv const> AgvConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::scheduling_msgs::Agv_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::scheduling_msgs::Agv_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace scheduling_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'scheduling_msgs': ['/home/ouiyeah/catkin_ws/src/scheduling_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::Agv_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::Agv_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::Agv_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::Agv_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::Agv_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::Agv_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::scheduling_msgs::Agv_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f01657a2f82714212a73e3a8e964b946";
  }

  static const char* value(const ::scheduling_msgs::Agv_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf01657a2f8271421ULL;
  static const uint64_t static_value2 = 0x2a73e3a8e964b946ULL;
};

template<class ContainerAllocator>
struct DataType< ::scheduling_msgs::Agv_<ContainerAllocator> >
{
  static const char* value()
  {
    return "scheduling_msgs/Agv";
  }

  static const char* value(const ::scheduling_msgs::Agv_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::scheduling_msgs::Agv_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 agvID\n\
string agvName\n\
bool isWorking\n\
bool isAgvBoot\n\
#bool isTaskOverTime\n\
int32 errorInfo\n\
#0 : no error\n\
#1 : obstacle\n\
#2 : battery low\n\
#3 : navigation error \n\
string working_station_name\n\
geometry_msgs/Pose pose\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::scheduling_msgs::Agv_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::scheduling_msgs::Agv_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.agvID);
      stream.next(m.agvName);
      stream.next(m.isWorking);
      stream.next(m.isAgvBoot);
      stream.next(m.errorInfo);
      stream.next(m.working_station_name);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Agv_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::scheduling_msgs::Agv_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::scheduling_msgs::Agv_<ContainerAllocator>& v)
  {
    s << indent << "agvID: ";
    Printer<int32_t>::stream(s, indent + "  ", v.agvID);
    s << indent << "agvName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.agvName);
    s << indent << "isWorking: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isWorking);
    s << indent << "isAgvBoot: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isAgvBoot);
    s << indent << "errorInfo: ";
    Printer<int32_t>::stream(s, indent + "  ", v.errorInfo);
    s << indent << "working_station_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.working_station_name);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHEDULING_MSGS_MESSAGE_AGV_H
