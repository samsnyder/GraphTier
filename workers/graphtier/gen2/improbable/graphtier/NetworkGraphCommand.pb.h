// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: improbable/graphtier/NetworkGraphCommand.proto

#ifndef PROTOBUF_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto__INCLUDED
#define PROTOBUF_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "improbable/entity_state.pb.h"
// @@protoc_insertion_point(includes)

namespace schema {
namespace improbable {
namespace graphtier {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
void protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

class NetworkGraphCommand;
class NetworkGraphCommandData;
class NetworkGraphCommand_Commands;
class NetworkGraphCommand_Events;
class NetworkGraphRequest;
class NetworkGraphResponse;

// ===================================================================

class NetworkGraphResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkGraphResponse) */ {
 public:
  NetworkGraphResponse();
  virtual ~NetworkGraphResponse();

  NetworkGraphResponse(const NetworkGraphResponse& from);

  inline NetworkGraphResponse& operator=(const NetworkGraphResponse& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetworkGraphResponse& default_instance();

  static const NetworkGraphResponse* internal_default_instance();

  void Swap(NetworkGraphResponse* other);

  // implements Message ----------------------------------------------

  inline NetworkGraphResponse* New() const { return New(NULL); }

  NetworkGraphResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkGraphResponse& from);
  void MergeFrom(const NetworkGraphResponse& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkGraphResponse* other);
  void UnsafeMergeFrom(const NetworkGraphResponse& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 field1_data = 1;
  bool has_field1_data() const;
  void clear_field1_data();
  static const int kField1DataFieldNumber = 1;
  ::google::protobuf::uint32 field1_data() const;
  void set_field1_data(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkGraphResponse)
 private:
  inline void set_has_field1_data();
  inline void clear_has_field1_data();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 field1_data_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkGraphResponse> NetworkGraphResponse_default_instance_;

// -------------------------------------------------------------------

class NetworkGraphRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkGraphRequest) */ {
 public:
  NetworkGraphRequest();
  virtual ~NetworkGraphRequest();

  NetworkGraphRequest(const NetworkGraphRequest& from);

  inline NetworkGraphRequest& operator=(const NetworkGraphRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetworkGraphRequest& default_instance();

  static const NetworkGraphRequest* internal_default_instance();

  void Swap(NetworkGraphRequest* other);

  // implements Message ----------------------------------------------

  inline NetworkGraphRequest* New() const { return New(NULL); }

  NetworkGraphRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkGraphRequest& from);
  void MergeFrom(const NetworkGraphRequest& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkGraphRequest* other);
  void UnsafeMergeFrom(const NetworkGraphRequest& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 field1_target_network_id = 1;
  bool has_field1_target_network_id() const;
  void clear_field1_target_network_id();
  static const int kField1TargetNetworkIdFieldNumber = 1;
  ::google::protobuf::int64 field1_target_network_id() const;
  void set_field1_target_network_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkGraphRequest)
 private:
  inline void set_has_field1_target_network_id();
  inline void clear_has_field1_target_network_id();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int64 field1_target_network_id_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkGraphRequest> NetworkGraphRequest_default_instance_;

// -------------------------------------------------------------------

class NetworkGraphCommandData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkGraphCommandData) */ {
 public:
  NetworkGraphCommandData();
  virtual ~NetworkGraphCommandData();

  NetworkGraphCommandData(const NetworkGraphCommandData& from);

  inline NetworkGraphCommandData& operator=(const NetworkGraphCommandData& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetworkGraphCommandData& default_instance();

  static const NetworkGraphCommandData* internal_default_instance();

  void Swap(NetworkGraphCommandData* other);

  // implements Message ----------------------------------------------

  inline NetworkGraphCommandData* New() const { return New(NULL); }

  NetworkGraphCommandData* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkGraphCommandData& from);
  void MergeFrom(const NetworkGraphCommandData& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkGraphCommandData* other);
  void UnsafeMergeFrom(const NetworkGraphCommandData& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkGraphCommandData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkGraphCommandData> NetworkGraphCommandData_default_instance_;

// -------------------------------------------------------------------

class NetworkGraphCommand_Events : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkGraphCommand.Events) */ {
 public:
  NetworkGraphCommand_Events();
  virtual ~NetworkGraphCommand_Events();

  NetworkGraphCommand_Events(const NetworkGraphCommand_Events& from);

  inline NetworkGraphCommand_Events& operator=(const NetworkGraphCommand_Events& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetworkGraphCommand_Events& default_instance();

  static const NetworkGraphCommand_Events* internal_default_instance();

  void Swap(NetworkGraphCommand_Events* other);

  // implements Message ----------------------------------------------

  inline NetworkGraphCommand_Events* New() const { return New(NULL); }

  NetworkGraphCommand_Events* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkGraphCommand_Events& from);
  void MergeFrom(const NetworkGraphCommand_Events& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkGraphCommand_Events* other);
  void UnsafeMergeFrom(const NetworkGraphCommand_Events& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkGraphCommand.Events)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkGraphCommand_Events> NetworkGraphCommand_Events_default_instance_;

// -------------------------------------------------------------------

class NetworkGraphCommand_Commands : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkGraphCommand.Commands) */ {
 public:
  NetworkGraphCommand_Commands();
  virtual ~NetworkGraphCommand_Commands();

  NetworkGraphCommand_Commands(const NetworkGraphCommand_Commands& from);

  inline NetworkGraphCommand_Commands& operator=(const NetworkGraphCommand_Commands& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetworkGraphCommand_Commands& default_instance();

  static const NetworkGraphCommand_Commands* internal_default_instance();

  void Swap(NetworkGraphCommand_Commands* other);

  // implements Message ----------------------------------------------

  inline NetworkGraphCommand_Commands* New() const { return New(NULL); }

  NetworkGraphCommand_Commands* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkGraphCommand_Commands& from);
  void MergeFrom(const NetworkGraphCommand_Commands& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkGraphCommand_Commands* other);
  void UnsafeMergeFrom(const NetworkGraphCommand_Commands& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .schema.improbable.graphtier.NetworkGraphRequest command_network_graph_request = 1;
  bool has_command_network_graph_request() const;
  void clear_command_network_graph_request();
  static const int kCommandNetworkGraphRequestFieldNumber = 1;
  const ::schema::improbable::graphtier::NetworkGraphRequest& command_network_graph_request() const;
  ::schema::improbable::graphtier::NetworkGraphRequest* mutable_command_network_graph_request();
  ::schema::improbable::graphtier::NetworkGraphRequest* release_command_network_graph_request();
  void set_allocated_command_network_graph_request(::schema::improbable::graphtier::NetworkGraphRequest* command_network_graph_request);

  // optional .schema.improbable.graphtier.NetworkGraphResponse command_network_graph_response = 2;
  bool has_command_network_graph_response() const;
  void clear_command_network_graph_response();
  static const int kCommandNetworkGraphResponseFieldNumber = 2;
  const ::schema::improbable::graphtier::NetworkGraphResponse& command_network_graph_response() const;
  ::schema::improbable::graphtier::NetworkGraphResponse* mutable_command_network_graph_response();
  ::schema::improbable::graphtier::NetworkGraphResponse* release_command_network_graph_response();
  void set_allocated_command_network_graph_response(::schema::improbable::graphtier::NetworkGraphResponse* command_network_graph_response);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkGraphCommand.Commands)
 private:
  inline void set_has_command_network_graph_request();
  inline void clear_has_command_network_graph_request();
  inline void set_has_command_network_graph_response();
  inline void clear_has_command_network_graph_response();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::schema::improbable::graphtier::NetworkGraphRequest* command_network_graph_request_;
  ::schema::improbable::graphtier::NetworkGraphResponse* command_network_graph_response_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkGraphCommand_Commands> NetworkGraphCommand_Commands_default_instance_;

// -------------------------------------------------------------------

class NetworkGraphCommand : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkGraphCommand) */ {
 public:
  NetworkGraphCommand();
  virtual ~NetworkGraphCommand();

  NetworkGraphCommand(const NetworkGraphCommand& from);

  inline NetworkGraphCommand& operator=(const NetworkGraphCommand& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetworkGraphCommand& default_instance();

  static const NetworkGraphCommand* internal_default_instance();

  void Swap(NetworkGraphCommand* other);

  // implements Message ----------------------------------------------

  inline NetworkGraphCommand* New() const { return New(NULL); }

  NetworkGraphCommand* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkGraphCommand& from);
  void MergeFrom(const NetworkGraphCommand& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NetworkGraphCommand* other);
  void UnsafeMergeFrom(const NetworkGraphCommand& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef NetworkGraphCommand_Events Events;
  typedef NetworkGraphCommand_Commands Commands;

  // accessors -------------------------------------------------------

  static const int kComponentExtensionFieldNumber = 8003;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityState,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkGraphCommandData >, 11, false >
    component_extension;
  static const int kEventExtensionFieldNumber = 8003;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityEvent,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkGraphCommand_Events >, 11, false >
    event_extension;
  static const int kCommandExtensionFieldNumber = 8003;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityCommand,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkGraphCommand_Commands >, 11, false >
    command_extension;
  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkGraphCommand)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkGraphCommand> NetworkGraphCommand_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// NetworkGraphResponse

// optional uint32 field1_data = 1;
inline bool NetworkGraphResponse::has_field1_data() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetworkGraphResponse::set_has_field1_data() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetworkGraphResponse::clear_has_field1_data() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetworkGraphResponse::clear_field1_data() {
  field1_data_ = 0u;
  clear_has_field1_data();
}
inline ::google::protobuf::uint32 NetworkGraphResponse::field1_data() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkGraphResponse.field1_data)
  return field1_data_;
}
inline void NetworkGraphResponse::set_field1_data(::google::protobuf::uint32 value) {
  set_has_field1_data();
  field1_data_ = value;
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.NetworkGraphResponse.field1_data)
}

inline const NetworkGraphResponse* NetworkGraphResponse::internal_default_instance() {
  return &NetworkGraphResponse_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkGraphRequest

// optional int64 field1_target_network_id = 1;
inline bool NetworkGraphRequest::has_field1_target_network_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetworkGraphRequest::set_has_field1_target_network_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetworkGraphRequest::clear_has_field1_target_network_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetworkGraphRequest::clear_field1_target_network_id() {
  field1_target_network_id_ = GOOGLE_LONGLONG(0);
  clear_has_field1_target_network_id();
}
inline ::google::protobuf::int64 NetworkGraphRequest::field1_target_network_id() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkGraphRequest.field1_target_network_id)
  return field1_target_network_id_;
}
inline void NetworkGraphRequest::set_field1_target_network_id(::google::protobuf::int64 value) {
  set_has_field1_target_network_id();
  field1_target_network_id_ = value;
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.NetworkGraphRequest.field1_target_network_id)
}

inline const NetworkGraphRequest* NetworkGraphRequest::internal_default_instance() {
  return &NetworkGraphRequest_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkGraphCommandData

inline const NetworkGraphCommandData* NetworkGraphCommandData::internal_default_instance() {
  return &NetworkGraphCommandData_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkGraphCommand_Events

inline const NetworkGraphCommand_Events* NetworkGraphCommand_Events::internal_default_instance() {
  return &NetworkGraphCommand_Events_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkGraphCommand_Commands

// optional .schema.improbable.graphtier.NetworkGraphRequest command_network_graph_request = 1;
inline bool NetworkGraphCommand_Commands::has_command_network_graph_request() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetworkGraphCommand_Commands::set_has_command_network_graph_request() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetworkGraphCommand_Commands::clear_has_command_network_graph_request() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetworkGraphCommand_Commands::clear_command_network_graph_request() {
  if (command_network_graph_request_ != NULL) command_network_graph_request_->::schema::improbable::graphtier::NetworkGraphRequest::Clear();
  clear_has_command_network_graph_request();
}
inline const ::schema::improbable::graphtier::NetworkGraphRequest& NetworkGraphCommand_Commands::command_network_graph_request() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_request)
  return command_network_graph_request_ != NULL ? *command_network_graph_request_
                         : *::schema::improbable::graphtier::NetworkGraphRequest::internal_default_instance();
}
inline ::schema::improbable::graphtier::NetworkGraphRequest* NetworkGraphCommand_Commands::mutable_command_network_graph_request() {
  set_has_command_network_graph_request();
  if (command_network_graph_request_ == NULL) {
    command_network_graph_request_ = new ::schema::improbable::graphtier::NetworkGraphRequest;
  }
  // @@protoc_insertion_point(field_mutable:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_request)
  return command_network_graph_request_;
}
inline ::schema::improbable::graphtier::NetworkGraphRequest* NetworkGraphCommand_Commands::release_command_network_graph_request() {
  // @@protoc_insertion_point(field_release:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_request)
  clear_has_command_network_graph_request();
  ::schema::improbable::graphtier::NetworkGraphRequest* temp = command_network_graph_request_;
  command_network_graph_request_ = NULL;
  return temp;
}
inline void NetworkGraphCommand_Commands::set_allocated_command_network_graph_request(::schema::improbable::graphtier::NetworkGraphRequest* command_network_graph_request) {
  delete command_network_graph_request_;
  command_network_graph_request_ = command_network_graph_request;
  if (command_network_graph_request) {
    set_has_command_network_graph_request();
  } else {
    clear_has_command_network_graph_request();
  }
  // @@protoc_insertion_point(field_set_allocated:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_request)
}

// optional .schema.improbable.graphtier.NetworkGraphResponse command_network_graph_response = 2;
inline bool NetworkGraphCommand_Commands::has_command_network_graph_response() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NetworkGraphCommand_Commands::set_has_command_network_graph_response() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NetworkGraphCommand_Commands::clear_has_command_network_graph_response() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NetworkGraphCommand_Commands::clear_command_network_graph_response() {
  if (command_network_graph_response_ != NULL) command_network_graph_response_->::schema::improbable::graphtier::NetworkGraphResponse::Clear();
  clear_has_command_network_graph_response();
}
inline const ::schema::improbable::graphtier::NetworkGraphResponse& NetworkGraphCommand_Commands::command_network_graph_response() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_response)
  return command_network_graph_response_ != NULL ? *command_network_graph_response_
                         : *::schema::improbable::graphtier::NetworkGraphResponse::internal_default_instance();
}
inline ::schema::improbable::graphtier::NetworkGraphResponse* NetworkGraphCommand_Commands::mutable_command_network_graph_response() {
  set_has_command_network_graph_response();
  if (command_network_graph_response_ == NULL) {
    command_network_graph_response_ = new ::schema::improbable::graphtier::NetworkGraphResponse;
  }
  // @@protoc_insertion_point(field_mutable:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_response)
  return command_network_graph_response_;
}
inline ::schema::improbable::graphtier::NetworkGraphResponse* NetworkGraphCommand_Commands::release_command_network_graph_response() {
  // @@protoc_insertion_point(field_release:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_response)
  clear_has_command_network_graph_response();
  ::schema::improbable::graphtier::NetworkGraphResponse* temp = command_network_graph_response_;
  command_network_graph_response_ = NULL;
  return temp;
}
inline void NetworkGraphCommand_Commands::set_allocated_command_network_graph_response(::schema::improbable::graphtier::NetworkGraphResponse* command_network_graph_response) {
  delete command_network_graph_response_;
  command_network_graph_response_ = command_network_graph_response;
  if (command_network_graph_response) {
    set_has_command_network_graph_response();
  } else {
    clear_has_command_network_graph_response();
  }
  // @@protoc_insertion_point(field_set_allocated:schema.improbable.graphtier.NetworkGraphCommand.Commands.command_network_graph_response)
}

inline const NetworkGraphCommand_Commands* NetworkGraphCommand_Commands::internal_default_instance() {
  return &NetworkGraphCommand_Commands_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkGraphCommand

inline const NetworkGraphCommand* NetworkGraphCommand::internal_default_instance() {
  return &NetworkGraphCommand_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace graphtier
}  // namespace improbable
}  // namespace schema

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_improbable_2fgraphtier_2fNetworkGraphCommand_2eproto__INCLUDED
