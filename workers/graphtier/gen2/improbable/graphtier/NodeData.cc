// Generated by SpatialOS codegen. DO NOT EDIT!
// source: improbable/graphtier/NodeData.schema
#include <improbable/graphtier/NodeData.h>
#include <improbable/entity_state.pb.h>
#include <improbable/graphtier/NodeData.pb.h>


#include <iostream>
using namespace std;

namespace improbable {
namespace graphtier {

// Implementation of NetworkAttachment.
//----------------------------------------------------------------

NetworkAttachment::NetworkAttachment(const ::worker::Option< ::worker::EntityId >& network)
: _network{network} {}

bool NetworkAttachment::operator==(const NetworkAttachment& value) const {
  return
      _network == value._network;
}

bool NetworkAttachment::operator!=(const NetworkAttachment& value) const {
  return !operator==(value);
}

const ::worker::Option< ::worker::EntityId >& NetworkAttachment::network() const {
  return _network;
}

::worker::Option< ::worker::EntityId >& NetworkAttachment::network() {
  return _network;
}

NetworkAttachment& NetworkAttachment::set_network(const ::worker::Option< ::worker::EntityId >& value) {
  _network = value;
  return *this;
}

// Implementation of NodeDataData.
//----------------------------------------------------------------


NodeDataData::NodeDataData(const ::worker::List< ::improbable::graphtier::NetworkAttachment >& networks)
: _networks{networks} {
  cout << "BB: " << networks.size() << endl;
}

  NodeDataData::NodeDataData(NodeDataData&& n){
    cout << "jj " << n.networks().size() << " " << &n << endl;
    this->_networks = n.networks();
  }

bool NodeDataData::operator==(const NodeDataData& value) const {
  return
      _networks == value._networks;
}

bool NodeDataData::operator!=(const NodeDataData& value) const {
  return !operator==(value);
}

const ::worker::List< ::improbable::graphtier::NetworkAttachment >& NodeDataData::networks() const {
  cout << "cfg: " << _networks.size() << endl;
  return _networks;
}

::worker::List< ::improbable::graphtier::NetworkAttachment >& NodeDataData::networks() {
  // cout << "aacfg: " << _networks.size() << endl;
  return _networks;
}

NodeDataData& NodeDataData::set_networks(const ::worker::List< ::improbable::graphtier::NetworkAttachment >& value) {
  cout << "cfg: " << _networks.size() << endl;
  _networks = value;
  return *this;
}

// Implementation of NodeData.
//----------------------------------------------------------------

constexpr const ::worker::ComponentId NodeData::ComponentId;

bool NodeData::Update::operator==(const NodeData::Update& value) const {
  return
      _networks == value._networks;
}

bool NodeData::Update::operator!=(const NodeData::Update& value) const {
  return !operator==(value);
}

NodeData::Update NodeData::Update::FromInitialData(const ::improbable::graphtier::NodeDataData& data) {
  NodeData::Update update;
  update._networks.emplace(data.networks());
  return update;
}

::improbable::graphtier::NodeDataData NodeData::Update::ToInitialData() const {
  return ::improbable::graphtier::NodeDataData(*_networks);
}

void NodeData::Update::ApplyTo(::improbable::graphtier::NodeDataData& data) const {
  if (_networks) {
    data.set_networks(*_networks);
  }
}

const ::worker::Option< ::worker::List< ::improbable::graphtier::NetworkAttachment > >& NodeData::Update::networks() const {
  return _networks;
}

::worker::Option< ::worker::List< ::improbable::graphtier::NetworkAttachment > >& NodeData::Update::networks() {
  return _networks;
}

NodeData::Update& NodeData::Update::set_networks(const ::worker::List< ::improbable::graphtier::NetworkAttachment >& value) {
  _networks.emplace(value); return *this;
}

// Serialization helpers.
//----------------------------------------------------------------

namespace detail {

void Serialize_NetworkAttachment(
    const ::improbable::graphtier::NetworkAttachment& data,
    ::schema::improbable::graphtier::NetworkAttachment& proto) {
  if (data.network()) {
    proto.set_field1_network(*data.network());
  }
}

::improbable::graphtier::NetworkAttachment Deserialize_NetworkAttachment(
    const ::schema::improbable::graphtier::NetworkAttachment& proto) {
  ::improbable::graphtier::NetworkAttachment result{
      {}};
  if (proto.has_field1_network()) {
    result.network().emplace(proto.field1_network());
  }
  return result;
}

void Serialize_NodeDataData(
    const ::improbable::graphtier::NodeDataData& data,
    ::schema::improbable::graphtier::NodeDataData& proto) {
  for (const auto& item : data.networks()) {
    ::improbable::graphtier::detail::Serialize_NetworkAttachment(item, *proto.add_field1_networks());
  }
}

::improbable::graphtier::NodeDataData Deserialize_NodeDataData(
    const ::schema::improbable::graphtier::NodeDataData& proto) {
  ::improbable::graphtier::NodeDataData result{
      {}};
  for (const auto& item : proto.field1_networks()) {
    auto n = ::improbable::graphtier::detail::Deserialize_NetworkAttachment(item);
    result.networks().emplace_back(n);
  }
  return result;
}

namespace {

void VtableBufferFree_NodeData(::worker::ComponentId, std::uint8_t* buffer) {
  delete[] buffer;
}

void VtableFree_NodeData(
    ::worker::ComponentId, std::uint8_t object_type,
    ::worker::detail::ClientObject* object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    delete static_cast< ::improbable::graphtier::NodeData::Update* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    delete static_cast< ::improbable::graphtier::NodeDataData* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request ||
             object_type == ::worker::detail::ClientComponentVtable::Response) {
    delete static_cast< GenericCommandObject_NodeData* >(object);
  }
}

::worker::detail::ClientObject* VtableCopy_NodeData(
    ::worker::ComponentId, std::uint8_t, ::worker::detail::ClientObject* object) {
  return object;
}

std::uint8_t VtableDeserialize_NodeData(
    ::worker::ComponentId, std::uint8_t object_type, const std::uint8_t* buffer,
    std::uint32_t length, ::worker::detail::ClientObject** object) {
  cout << "des nodedata" << endl;
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    *object = new ::improbable::graphtier::NodeData::Update;
    auto client_object = static_cast< ::improbable::graphtier::NodeData::Update* >(*object);
    {
      const auto& proto = proto_wrapper.entity_state().GetExtension(::schema::improbable::graphtier::NodeData::component_extension);

      std::set<std::uint32_t> fields_to_clear{proto_wrapper.fields_to_clear().begin(),
                                              proto_wrapper.fields_to_clear().end()};
      if (!proto.field1_networks().empty() || fields_to_clear.count(1)) {
        client_object->networks().emplace();
        for (const auto& item : proto.field1_networks()) {
          client_object->networks()->emplace_back(::improbable::graphtier::detail::Deserialize_NetworkAttachment(item));
        }
      }
    }
    {
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::graphtier::NodeData::component_extension);

    auto temp = ::improbable::graphtier::detail::Deserialize_NodeDataData(proto);
    *object = new ::improbable::graphtier::NodeDataData{temp};

    NodeDataData* dataObj = (NodeDataData*) (*object);

    cout << "hh " << dataObj << " " << dataObj->networks().size() << endl;
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
  }
  return true;
}

void VtableSerialize_NodeData(
    ::worker::ComponentId, std::uint8_t object_type,
    const ::worker::detail::ClientObject* object, std::uint8_t** buffer,
    std::uint32_t* length) {
  static_cast<void>(object);
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    const auto& data = *static_cast<const ::improbable::graphtier::NodeData::Update*>(object);
    {
      auto& proto = *proto_wrapper.mutable_entity_state()->MutableExtension(::schema::improbable::graphtier::NodeData::component_extension);
      if (data.networks()) {
        if (data.networks()->empty()) {
          proto_wrapper.add_fields_to_clear(1);
        }
        for (const auto& item : *data.networks()) {
          ::improbable::graphtier::detail::Serialize_NetworkAttachment(item, *proto.add_field1_networks());
        }
      }
    }
    {
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    const auto& data = *static_cast<const ::improbable::graphtier::NodeDataData*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::graphtier::NodeData::component_extension);

    ::improbable::graphtier::detail::Serialize_NodeDataData(data, proto);
    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    proto_wrapper.MutableExtension(::schema::improbable::graphtier::NodeData::command_extension);


    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    proto_wrapper.MutableExtension(::schema::improbable::graphtier::NodeData::command_extension);


    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  }
}

}  // anonymous namespace

const ::worker::detail::ClientComponentVtable& Vtable_NodeData() {
  static const ::worker::detail::ClientComponentVtable vtable = {
      8006,
      &detail::VtableBufferFree_NodeData,
      &detail::VtableFree_NodeData,
      &detail::VtableCopy_NodeData,
      &detail::VtableDeserialize_NodeData,
      &detail::VtableSerialize_NodeData,
  };
  return vtable;
}

}  // ::detail

}  // ::graphtier
}  // ::improbable
