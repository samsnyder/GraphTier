// Generated by SpatialOS codegen. DO NOT EDIT!
// source: improbable/core/PlayerCreation.schema
#include <improbable/core/PlayerCreation.h>
#include <improbable/entity_state.pb.h>
#include <improbable/core/PlayerCreation.pb.h>

namespace improbable {
namespace core {

// Implementation of CreatePlayerRequest.
//----------------------------------------------------------------

CreatePlayerRequest::CreatePlayerRequest() {}

bool CreatePlayerRequest::operator==(const CreatePlayerRequest&) const {
  return true;
}

bool CreatePlayerRequest::operator!=(const CreatePlayerRequest& value) const {
  return !operator==(value);
}

// Implementation of CreatePlayerResponse.
//----------------------------------------------------------------

CreatePlayerResponse::CreatePlayerResponse() {}

bool CreatePlayerResponse::operator==(const CreatePlayerResponse&) const {
  return true;
}

bool CreatePlayerResponse::operator!=(const CreatePlayerResponse& value) const {
  return !operator==(value);
}

// Implementation of PlayerCreationData.
//----------------------------------------------------------------

PlayerCreationData::PlayerCreationData() {}

bool PlayerCreationData::operator==(const PlayerCreationData&) const {
  return true;
}

bool PlayerCreationData::operator!=(const PlayerCreationData& value) const {
  return !operator==(value);
}

// Implementation of PlayerCreation.
//----------------------------------------------------------------

constexpr const ::worker::ComponentId PlayerCreation::ComponentId;

constexpr const std::uint32_t PlayerCreation::Commands::CreatePlayer::CommandId;

bool PlayerCreation::Update::operator==(const PlayerCreation::Update&) const {
  return true;
}

bool PlayerCreation::Update::operator!=(const PlayerCreation::Update& value) const {
  return !operator==(value);
}

PlayerCreation::Update PlayerCreation::Update::FromInitialData(const ::improbable::core::PlayerCreationData&) {
  return PlayerCreation::Update{};
}

::improbable::core::PlayerCreationData PlayerCreation::Update::ToInitialData() const {
  return ::improbable::core::PlayerCreationData();
}

void PlayerCreation::Update::ApplyTo(::improbable::core::PlayerCreationData&) const {
}

// Serialization helpers.
//----------------------------------------------------------------

namespace detail {

void Serialize_CreatePlayerRequest(
    const ::improbable::core::CreatePlayerRequest&,
    ::schema::improbable::core::CreatePlayerRequest&) {}

::improbable::core::CreatePlayerRequest Deserialize_CreatePlayerRequest(
    const ::schema::improbable::core::CreatePlayerRequest&) {
  return {};
}

void Serialize_CreatePlayerResponse(
    const ::improbable::core::CreatePlayerResponse&,
    ::schema::improbable::core::CreatePlayerResponse&) {}

::improbable::core::CreatePlayerResponse Deserialize_CreatePlayerResponse(
    const ::schema::improbable::core::CreatePlayerResponse&) {
  return {};
}

void Serialize_PlayerCreationData(
    const ::improbable::core::PlayerCreationData&,
    ::schema::improbable::core::PlayerCreationData&) {}

::improbable::core::PlayerCreationData Deserialize_PlayerCreationData(
    const ::schema::improbable::core::PlayerCreationData&) {
  return {};
}

namespace {

void VtableBufferFree_PlayerCreation(::worker::ComponentId, std::uint8_t* buffer) {
  delete[] buffer;
}

void VtableFree_PlayerCreation(
    ::worker::ComponentId, std::uint8_t object_type,
    ::worker::detail::ClientObject* object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    delete static_cast< ::improbable::core::PlayerCreation::Update* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    delete static_cast< ::improbable::core::PlayerCreationData* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request ||
             object_type == ::worker::detail::ClientComponentVtable::Response) {
    delete static_cast< GenericCommandObject_PlayerCreation* >(object);
  }
}

::worker::detail::ClientObject* VtableCopy_PlayerCreation(
    ::worker::ComponentId, std::uint8_t, ::worker::detail::ClientObject* object) {
  return object;
}

std::uint8_t VtableDeserialize_PlayerCreation(
    ::worker::ComponentId, std::uint8_t object_type, const std::uint8_t* buffer,
    std::uint32_t length, ::worker::detail::ClientObject** object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    *object = new ::improbable::core::PlayerCreation::Update;
    {
    }
    {
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::core::PlayerCreation::component_extension);

    *object = new ::improbable::core::PlayerCreationData{::improbable::core::detail::Deserialize_PlayerCreationData(proto)};
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::core::PlayerCreation::command_extension);

    if (proto.has_command_create_player_request()) {
      *object = new detail::GenericCommandObject_PlayerCreation{
          ::improbable::core::PlayerCreation::Commands::CreatePlayer::CommandId,
         ::improbable::core::detail::Deserialize_CreatePlayerRequest(proto.command_create_player_request())};
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::core::PlayerCreation::command_extension);

    if (proto.has_command_create_player_response()) {
      *object = new detail::GenericCommandObject_PlayerCreation{
          ::improbable::core::PlayerCreation::Commands::CreatePlayer::CommandId,
          ::improbable::core::detail::Deserialize_CreatePlayerResponse(proto.command_create_player_response())};
    }
  }
  return true;
}

void VtableSerialize_PlayerCreation(
    ::worker::ComponentId, std::uint8_t object_type,
    const ::worker::detail::ClientObject* object, std::uint8_t** buffer,
    std::uint32_t* length) {
  static_cast<void>(object);
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    {
      proto_wrapper.mutable_entity_state()->MutableExtension(::schema::improbable::core::PlayerCreation::component_extension);
    }
    {
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    const auto& data = *static_cast<const ::improbable::core::PlayerCreationData*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::core::PlayerCreation::component_extension);

    ::improbable::core::detail::Serialize_PlayerCreationData(data, proto);
    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    const auto& data = *static_cast<const GenericCommandObject_PlayerCreation*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::core::PlayerCreation::command_extension);

    if (data.CommandId == ::improbable::core::PlayerCreation::Commands::CreatePlayer::CommandId) {
      ::improbable::core::detail::Serialize_CreatePlayerRequest(*data.CommandObject.data< ::improbable::core::CreatePlayerRequest >(), *proto.mutable_command_create_player_request());
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    const auto& data = *static_cast<const GenericCommandObject_PlayerCreation*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::core::PlayerCreation::command_extension);

    if (data.CommandId == ::improbable::core::PlayerCreation::Commands::CreatePlayer::CommandId) {
      ::improbable::core::detail::Serialize_CreatePlayerResponse(*data.CommandObject.data< ::improbable::core::CreatePlayerResponse >(), *proto.mutable_command_create_player_response());
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  }
}

}  // anonymous namespace

const ::worker::detail::ClientComponentVtable& Vtable_PlayerCreation() {
  static const ::worker::detail::ClientComponentVtable vtable = {
      1001,
      &detail::VtableBufferFree_PlayerCreation,
      &detail::VtableFree_PlayerCreation,
      &detail::VtableCopy_PlayerCreation,
      &detail::VtableDeserialize_PlayerCreation,
      &detail::VtableSerialize_PlayerCreation,
  };
  return vtable;
}

}  // ::detail

}  // ::core
}  // ::improbable
