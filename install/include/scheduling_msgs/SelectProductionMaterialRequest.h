// Generated by gencpp from file scheduling_msgs/SelectProductionMaterialRequest.msg
// DO NOT EDIT!


#ifndef SCHEDULING_MSGS_MESSAGE_SELECTPRODUCTIONMATERIALREQUEST_H
#define SCHEDULING_MSGS_MESSAGE_SELECTPRODUCTIONMATERIALREQUEST_H


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
struct SelectProductionMaterialRequest_
{
  typedef SelectProductionMaterialRequest_<ContainerAllocator> Type;

  SelectProductionMaterialRequest_()
    : key()
    , value()  {
    }
  SelectProductionMaterialRequest_(const ContainerAllocator& _alloc)
    : key(_alloc)
    , value(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _key_type;
  _key_type key;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _value_type;
  _value_type value;




  typedef boost::shared_ptr< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SelectProductionMaterialRequest_

typedef ::scheduling_msgs::SelectProductionMaterialRequest_<std::allocator<void> > SelectProductionMaterialRequest;

typedef boost::shared_ptr< ::scheduling_msgs::SelectProductionMaterialRequest > SelectProductionMaterialRequestPtr;
typedef boost::shared_ptr< ::scheduling_msgs::SelectProductionMaterialRequest const> SelectProductionMaterialRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cf57fdc6617a881a88c16e768132149c";
  }

  static const char* value(const ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcf57fdc6617a881aULL;
  static const uint64_t static_value2 = 0x88c16e768132149cULL;
};

template<class ContainerAllocator>
struct DataType< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "scheduling_msgs/SelectProductionMaterialRequest";
  }

  static const char* value(const ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
string key\n\
\n\
string value\n\
";
  }

  static const char* value(const ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.key);
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SelectProductionMaterialRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::scheduling_msgs::SelectProductionMaterialRequest_<ContainerAllocator>& v)
  {
    s << indent << "key: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.key);
    s << indent << "value: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SCHEDULING_MSGS_MESSAGE_SELECTPRODUCTIONMATERIALREQUEST_H
