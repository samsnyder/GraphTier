// Generated by SpatialOS codegen. DO NOT EDIT!
// source: improbable/core/WorldTransform.schema
#include <improbable/core/WorldTransform.h>
#include <improbable/entity_state.pb.h>
#include <improbable/core/WorldTransform.pb.h>

namespace improbable {
namespace core {

// Implementation of WorldTransformData.
//----------------------------------------------------------------

WorldTransformData::WorldTransformData(
    const ::improbable::math::Coordinates& position,
    const ::improbable::core::Quaternion& rotation)
: _position{position}
, _rotation{rotation} {}

bool WorldTransformData::operator==(const WorldTransformData& value) const {
  return
      _position == value._position &&
      _rotation == value._rotation;
}

bool WorldTransformData::operator!=(const WorldTransformData& value) const {
  return !operator==(value);
}

const ::improbable::math::Coordinates& WorldTransformData::position() const {
  return _position;
}

::improbable::math::Coordinates& WorldTransformData::position() {
  return _position;
}

WorldTransformData& WorldTransformData::set_position(const ::improbable::math::Coordinates& value) {
  _position = value;
  return *this;
}

const ::improbable::core::Quaternion& WorldTransformData::rotation() const {
  return _rotation;
}

::improbable::core::Quaternion& WorldTransformData::rotation() {
  return _rotation;
}

WorldTransformData& WorldTransformData::set_rotation(const ::improbable::core::Quaternion& value) {
  _rotation = value;
  return *this;
}

// Implementation of WorldTransform.
//----------------------------------------------------------------

constexpr const ::worker::ComponentId WorldTransform::ComponentId;

bool WorldTransform::Update::operator==(const WorldTransform::Update& value) const {
  return
      _position == value._position &&
      _rotation == value._rotation;
}

bool WorldTransform::Update::operator!=(const WorldTransform::Update& value) const {
  return !operator==(value);
}

WorldTransform::Update WorldTransform::Update::FromInitialData(const ::improbable::core::WorldTransformData& data) {
  WorldTransform::Update update;
  update._position.emplace(data.position());
  update._rotation.emplace(data.rotation());
  return update;
}

::improbable::core::WorldTransformData WorldTransform::Update::ToInitialData() const {
  return ::improbable::core::WorldTransformData(
      *_position,
      *_rotation);
}

void WorldTransform::Update::ApplyTo(::improbable::core::WorldTransformData& data) const {
  if (_position) {
    data.set_position(*_position);
  }
  if (_rotation) {
    data.set_rotation(*_rotation);
  }
}

const ::worker::Option< ::improbable::math::Coordinates >& WorldTransform::Update::position() const {
  return _position;
}

::worker::Option< ::improbable::math::Coordinates >& WorldTransform::Update::position() {
  return _position;
}

WorldTransform::Update& WorldTransform::Update::set_position(const ::improbable::math::Coordinates& value) {
  _position.emplace(value); return *this;
}

const ::worker::Option< ::improbable::core::Quaternion >& WorldTransform::Update::rotation() const {
  return _rotation;
}

::worker::Option< ::improbable::core::Quaternion >& WorldTransform::Update::rotation() {
  return _rotation;
}

WorldTransform::Update& WorldTransform::Update::set_rotation(const ::improbable::core::Quaternion& value) {
  _rotation.emplace(value); return *this;
}

// Serialization helpers.
//----------------------------------------------------------------

namespace detail {

void Serialize_WorldTransformData(
    const ::improbable::core::WorldTransformData& data,
    ::schema::improbable::core::WorldTransformData& proto) {
  ::improbable::math::detail::Serialize_Coordinates(data.position(), *proto.mutable_field1_position());
  ::improbable::core::detail::Serialize_Quaternion(data.rotation(), *proto.mutable_field2_rotation());
}

::improbable::core::WorldTransformData Deserialize_WorldTransformData(
    const ::schema::improbable::core::WorldTransformData& proto) {
  ::improbable::core::WorldTransformData result{
      ::improbable::math::detail::Deserialize_Coordinates(proto.field1_position()),
      ::improbable::core::detail::Deserialize_Quaternion(proto.field2_rotation())};
  return result;
}

namespace {

void VtableBufferFree_WorldTransform(::worker::ComponentId, std::uint8_t* buffer) {
  delete[] buffer;
}

void VtableFree_WorldTransform(
    ::worker::ComponentId, std::uint8_t object_type,
    ::worker::detail::ClientObject* object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    delete static_cast< ::improbable::core::WorldTransform::Update* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    delete static_cast< ::improbable::core::WorldTransformData* >(object);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request ||
             object_type == ::worker::detail::ClientComponentVtable::Response) {
    delete static_cast< GenericCommandObject_WorldTransform* >(object);
  }
}

::worker::detail::ClientObject* VtableCopy_WorldTransform(
    ::worker::ComponentId, std::uint8_t, ::worker::detail::ClientObject* object) {
  return object;
}

std::uint8_t VtableDeserialize_WorldTransform(
    ::worker::ComponentId, std::uint8_t object_type, const std::uint8_t* buffer,
    std::uint32_t length, ::worker::detail::ClientObject** object) {
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    *object = new ::improbable::core::WorldTransform::Update;
    auto client_object = static_cast< ::improbable::core::WorldTransform::Update* >(*object);
    {
      const auto& proto = proto_wrapper.entity_state().GetExtension(::schema::improbable::core::WorldTransform::component_extension);

      std::set<std::uint32_t> fields_to_clear{proto_wrapper.fields_to_clear().begin(),
                                              proto_wrapper.fields_to_clear().end()};
      if (proto.has_field1_position()) {
        client_object->position().emplace(::improbable::math::detail::Deserialize_Coordinates(proto.field1_position()));
      }
      if (proto.has_field2_rotation()) {
        client_object->rotation().emplace(::improbable::core::detail::Deserialize_Quaternion(proto.field2_rotation()));
      }
    }
    {
    }
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    if (!proto_wrapper.ParseFromArray(buffer, length)) {
      return false;
    }
    const auto& proto = proto_wrapper.GetExtension(::schema::improbable::core::WorldTransform::component_extension);

    *object = new ::improbable::core::WorldTransformData{::improbable::core::detail::Deserialize_WorldTransformData(proto)};
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

void VtableSerialize_WorldTransform(
    ::worker::ComponentId, std::uint8_t object_type,
    const ::worker::detail::ClientObject* object, std::uint8_t** buffer,
    std::uint32_t* length) {
  static_cast<void>(object);
  if (object_type == ::worker::detail::ClientComponentVtable::Update) {
    ::schema::improbable::EntityComponentUpdate proto_wrapper;
    const auto& data = *static_cast<const ::improbable::core::WorldTransform::Update*>(object);
    {
      auto& proto = *proto_wrapper.mutable_entity_state()->MutableExtension(::schema::improbable::core::WorldTransform::component_extension);
      if (data.position()) {
        ::improbable::math::detail::Serialize_Coordinates(*data.position(), *proto.mutable_field1_position());
      }
      if (data.rotation()) {
        ::improbable::core::detail::Serialize_Quaternion(*data.rotation(), *proto.mutable_field2_rotation());
      }
    }
    {
    }

    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Snapshot) {
    ::schema::improbable::EntityState proto_wrapper;
    const auto& data = *static_cast<const ::improbable::core::WorldTransformData*>(object);
    auto& proto = *proto_wrapper.MutableExtension(::schema::improbable::core::WorldTransform::component_extension);

    ::improbable::core::detail::Serialize_WorldTransformData(data, proto);
    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Request) {
    ::schema::improbable::EntityCommand proto_wrapper;
    proto_wrapper.MutableExtension(::schema::improbable::core::WorldTransform::command_extension);


    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  } else if (object_type == ::worker::detail::ClientComponentVtable::Response) {
    ::schema::improbable::EntityCommand proto_wrapper;
    proto_wrapper.MutableExtension(::schema::improbable::core::WorldTransform::command_extension);


    *length = proto_wrapper.ByteSize();
    *buffer = new std::uint8_t[*length];
    proto_wrapper.SerializeToArray(*buffer, *length);
  }
}

}  // anonymous namespace

const ::worker::detail::ClientComponentVtable& Vtable_WorldTransform() {
  static const ::worker::detail::ClientComponentVtable vtable = {
      1000,
      &detail::VtableBufferFree_WorldTransform,
      &detail::VtableFree_WorldTransform,
      &detail::VtableCopy_WorldTransform,
      &detail::VtableDeserialize_WorldTransform,
      &detail::VtableSerialize_WorldTransform,
  };
  return vtable;
}

}  // ::detail

}  // ::core
}  // ::improbable
