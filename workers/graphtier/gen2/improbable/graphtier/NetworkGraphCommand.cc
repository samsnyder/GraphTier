// Generated by SpatialOS codegen. DO NOT EDIT!
// source: improbable/graphtier/NetworkGraphCommand.schema
#include <improbable/graphtier/NetworkGraphCommand.h>
#include <improbable/entity_state.pb.h>
#include <improbable/graphtier/NetworkGraphCommand.pb.h>

namespace improbable {
namespace graphtier {

// Implementation of NetworkGraphCommandData.
//----------------------------------------------------------------

NetworkGraphCommandData::NetworkGraphCommandData() {}

bool NetworkGraphCommandData::operator==(const NetworkGraphCommandData&) const {
  return true;
}

bool NetworkGraphCommandData::operator!=(const NetworkGraphCommandData& value) const {
  return !operator==(value);
}

// Implementation of NetworkGraphRequest.
//----------------------------------------------------------------

NetworkGraphRequest::NetworkGraphRequest(::worker::EntityId target_network_id)
: _target_network_id{target_network_id} {}

bool NetworkGraphRequest::operator==(const NetworkGraphRequest& value) const {
  return
      _target_network_id == value._target_network_id;
}

bool NetworkGraphRequest::operator!=(const NetworkGraphRequest& value) const {
  return !operator==(value);
}

::worker::EntityId NetworkGraphRequest::target_network_id() const {
  return _target_network_id;
}

::worker::EntityId& NetworkGraphRequest::target_network_id() {
  return _target_network_id;
}

NetworkGraphRequest& NetworkGraphRequest::set_target_network_id(::worker::EntityId value) {
  _target_network_id = value;
  return *this;
}

// Implementation of NetworkGraphResponse.
//----------------------------------------------------------------

NetworkGraphResponse::NetworkGraphResponse(std::uint32_t data)
: _data{data} {}

bool NetworkGraphResponse::operator==(const NetworkGraphResponse& value) const {
  return
      _data == value._data;
}

bool NetworkGraphResponse::operator!=(const NetworkGraphResponse& value) const {
  return !operator==(value);
}

std::uint32_t NetworkGraphResponse::data() const {
  return _data;
}

std::uint32_t& NetworkGraphResponse::data() {
  return _data;
}

NetworkGraphResponse& NetworkGraphResponse::set_data(std::uint32_t value) {
  _data = value;
  return *this;
}

// Implementation of NetworkGraphCommand.
//----------------------------------------------------------------

constexpr const ::worker::ComponentId NetworkGraphCommand::ComponentId;

constexpr const std::uint32_t NetworkGraphCommand::Commands::NetworkGraph::CommandId;

bool NetworkGraphCommand::Update::operator==(const NetworkGraphCommand::Update&) const {
  return true;
}

bool NetworkGraphCommand::Update::operator!=(const NetworkGraphCommand::Update& value) const {
  return !operator==(value);
}

NetworkGraphCommand::Update NetworkGraphCommand::Update::FromInitialData(const ::improbable::graphtier::NetworkGraphCommandData&) {
  return NetworkGraphCommand::Update{};
}

::improbable::graphtier::NetworkGraphCommandData NetworkGraphCommand::Update::ToInitialData() const {
  return ::improbable::graphtier::NetworkGraphCommandData();
}

void NetworkGraphCommand::Update::ApplyTo(::improbable::graphtier::NetworkGraphCommandData&) const {
}

// Serialization helpers.
//----------------------------------------------------------------

namespace detail {

void Serialize_NetworkGraphCommandData(
    const ::improbable::graphtier::NetworkGraphCommandData&,
    ::schema::improbable::graphtier::NetworkGraphCommandData&) {}

::improbable::graphtier::NetworkGraphCommandData Deserialize_NetworkGraphCommandData(
    const ::schema::improbable::graphtier::NetworkGraphCommandData&) {
  return {};
}

void Serialize_NetworkGraphRequest(
    const ::improbable::graphtier::NetworkGraphRequest& data,
    ::schema::improbable::graphtier::NetworkGraphRequest& proto) {
  proto.set_field1_target_network_id(data.target_network_id());
}

::improbable::graphtier::NetworkGraphRequest Deserialize_NetworkGraphRequest(
    const ::schema::improbable::graphtier::NetworkGraphRequest& proto) {
  ::improbable::graphtier::NetworkGraphRequest result{
      proto.field1_target_network_id()};
  return result;
}

void Serialize_NetworkGraphResponse(
    const ::improbable::graphtier::NetworkGraphResponse& data,
    ::schema::improbable::graphtier::NetworkGraphResponse& proto) {
  proto.set_field1_data(data.data());
}

::improbable::graphtier::NetworkGraphResponse Deserialize_NetworkGraphResponse(
    const ::schema::improbable::graphtier::NetworkGraphResponse& proto) {
  ::improbable::graphtier::NetworkGraphResponse result{
      proto.field1_data()};
  return result;
}

namespace {

void VtableBufferFree_NetworkGraphCommand(::worker::ComponentId, std::uint8_t* buffer) {
  delete[] buffer;
}

void VtableFree_NetworkGraphCommand(
    ::worker::ComponentId, std::uint8_t object_type,
    ::worker::detail::ClientObject* object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    delete static_cast< ::improbable::graphtier::NetworkGraphCommand::Update* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    delete static_cast< ::improbable::graphtier::NetworkGraphCommandData* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request ||
             object_type == ::worker::detail::ClientComponentVtable::Response) {
    delete static_cast< GenericCommandObject_NetworkGraphCommand* >(object);
  }
}

::worker::detail::ClientObject* VtableCopy_NetworkGraphCommand(
    ::worker::ComponentId, std::uint8_t, ::worker::detail::ClientObject* object) {
  return object;
}

std::uint8_t VtableDeserialize_NetworkGraphCommand(
    ::worker::ComponentId, std::uint8_t object_type, const std::uint8_t* buffer,
    std::uint32_t length, ::worker::detail::ClientObject** object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    *object = new ::improbable::graphtier::NetworkGraphCommand::Update;
    {
    }
    {
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::graphtier::NetworkGraphCommand::component_extension);

    *object = new ::improbable::graphtier::NetworkGraphCommandData{::improbable::graphtier::detail::Deserialize_NetworkGraphCommandData(proto)};
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::graphtier::NetworkGraphCommand::command_extension);

    if (proto.has_command_network_graph_request()) {
      *object = new detail::GenericCommandObject_NetworkGraphCommand{
          ::improbable::graphtier::NetworkGraphCommand::Commands::NetworkGraph::CommandId,
         ::improbable::graphtier::detail::Deserialize_NetworkGraphRequest(proto.command_network_graph_request())};
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::graphtier::NetworkGraphCommand::command_extension);

    if (proto.has_command_network_graph_response()) {
      *object = new detail::GenericCommandObject_NetworkGraphCommand{
          ::improbable::graphtier::NetworkGraphCommand::Commands::NetworkGraph::CommandId,
          ::improbable::graphtier::detail::Deserialize_NetworkGraphResponse(proto.command_network_graph_response())};
    }
  }
  return true;
}

void VtableSerialize_NetworkGraphCommand(
    ::worker::ComponentId, std::uint8_t object_type,
    const ::worker::detail::ClientObject* object, std::uint8_t** buffer,
    std::uint32_t* length) {
  static_cast<void>(object);
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    {
      proto_wrapper.mutable_entity_state()->MutableExtension(::schema::improbable::graphtier::NetworkGraphCommand::component_extension);
    }
    {
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    const auto& data = *static_cast<const ::improbable::graphtier::NetworkGraphCommandData*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::graphtier::NetworkGraphCommand::component_extension);

    ::improbable::graphtier::detail::Serialize_NetworkGraphCommandData(data, proto);
    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    const auto& data = *static_cast<const GenericCommandObject_NetworkGraphCommand*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::graphtier::NetworkGraphCommand::command_extension);

    if (data.CommandId == ::improbable::graphtier::NetworkGraphCommand::Commands::NetworkGraph::CommandId) {
      ::improbable::graphtier::detail::Serialize_NetworkGraphRequest(*data.CommandObject.data< ::improbable::graphtier::NetworkGraphRequest >(), *proto.mutable_command_network_graph_request());
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    const auto& data = *static_cast<const GenericCommandObject_NetworkGraphCommand*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::graphtier::NetworkGraphCommand::command_extension);

    if (data.CommandId == ::improbable::graphtier::NetworkGraphCommand::Commands::NetworkGraph::CommandId) {
      ::improbable::graphtier::detail::Serialize_NetworkGraphResponse(*data.CommandObject.data< ::improbable::graphtier::NetworkGraphResponse >(), *proto.mutable_command_network_graph_response());
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  }
}

}  // anonymous namespace

const ::worker::detail::ClientComponentVtable& Vtable_NetworkGraphCommand() {
  static const ::worker::detail::ClientComponentVtable vtable = {
      8003,
      &detail::VtableBufferFree_NetworkGraphCommand,
      &detail::VtableFree_NetworkGraphCommand,
      &detail::VtableCopy_NetworkGraphCommand,
      &detail::VtableDeserialize_NetworkGraphCommand,
      &detail::VtableSerialize_NetworkGraphCommand,
  };
  return vtable;
}

}  // ::detail

}  // ::graphtier
}  // ::improbable
