// Generated by gencpp from file scheduling_msgs/QueryPathOnlyResponse.msg
// DO NOT EDIT!


#ifndef SCHEDULING_MSGS_MESSAGE_QUERYPATHONLYRESPONSE_H
#define SCHEDULING_MSGS_MESSAGE_QUERYPATHONLYRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace scheduling_msgs
{
template <class ContainerAllocator>
struct QueryPathOnlyResponse_
{
  typedef QueryPathOnlyResponse_<ContainerAllocator> Type;

  QueryPathOnlyResponse_()
    : isValid(false)  {
    }
  QueryPathOnlyResponse_(const ContainerAllocator& _alloc)
    : isValid(false)  {
  (void)_alloc;
    }



   typedef uint8_t _isValid_type;
  _isValid_type isValid;




  typedef boost::shared_ptr< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> const> ConstPtr;

}; // struct QueryPathOnlyResponse_

typedef ::scheduling_msgs::QueryPathOnlyResponse_<std::allocator<void> > QueryPathOnlyResponse;

typedef boost::shared_ptr< ::scheduling_msgs::QueryPathOnlyResponse > QueryPathOnlyResponsePtr;
typedef boost::shared_ptr< ::scheduling_msgs::QueryPathOnlyResponse const> QueryPathOnlyResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace scheduling_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'scheduling_msgs': ['/home/ouiyeah/catkin_ws/src/scheduling_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "708ef19af795518626307bebc19e81e8";
  }

  static const char* value(const ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x708ef19af7955186ULL;
  static const uint64_t static_value2 = 0x26307bebc19e81e8ULL;
};

template<class ContainerAllocator>
struct DataType< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "scheduling_msgs/QueryPathOnlyResponse";
  }

  static const char* value(const ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool isValid\n\
\n\
";
  }

  static const char* value(const ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.isValid);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct QueryPathOnlyResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::scheduling_msgs::QueryPathOnlyResponse_<ContainerAllocator>& v)
  {
    s << indent << "isValid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.isValid);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHEDULING_MSGS_MESSAGE_QUERYPATHONLYRESPONSE_H
