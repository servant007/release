// Generated by gencpp from file base_local_planner/GetLineCostResponse.msg
// DO NOT EDIT!


#ifndef BASE_LOCAL_PLANNER_MESSAGE_GETLINECOSTRESPONSE_H
#define BASE_LOCAL_PLANNER_MESSAGE_GETLINECOSTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace base_local_planner
{
template <class ContainerAllocator>
struct GetLineCostResponse_
{
  typedef GetLineCostResponse_<ContainerAllocator> Type;

  GetLineCostResponse_()
    : cost(0.0)  {
    }
  GetLineCostResponse_(const ContainerAllocator& _alloc)
    : cost(0.0)  {
  (void)_alloc;
    }



   typedef double _cost_type;
  _cost_type cost;




  typedef boost::shared_ptr< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetLineCostResponse_

typedef ::base_local_planner::GetLineCostResponse_<std::allocator<void> > GetLineCostResponse;

typedef boost::shared_ptr< ::base_local_planner::GetLineCostResponse > GetLineCostResponsePtr;
typedef boost::shared_ptr< ::base_local_planner::GetLineCostResponse const> GetLineCostResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::base_local_planner::GetLineCostResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace base_local_planner

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'base_local_planner': ['/home/ouiyeah/catkin_ws/src/navigation-jade-devel/base_local_planner/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bff9a2439f6a3b435a395e2c861c4c14";
  }

  static const char* value(const ::base_local_planner::GetLineCostResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbff9a2439f6a3b43ULL;
  static const uint64_t static_value2 = 0x5a395e2c861c4c14ULL;
};

template<class ContainerAllocator>
struct DataType< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "base_local_planner/GetLineCostResponse";
  }

  static const char* value(const ::base_local_planner::GetLineCostResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 cost\n\
\n\
";
  }

  static const char* value(const ::base_local_planner::GetLineCostResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cost);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetLineCostResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::base_local_planner::GetLineCostResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::base_local_planner::GetLineCostResponse_<ContainerAllocator>& v)
  {
    s << indent << "cost: ";
    Printer<double>::stream(s, indent + "  ", v.cost);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BASE_LOCAL_PLANNER_MESSAGE_GETLINECOSTRESPONSE_H