// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: improbable/graphtier/NetworkCommands.proto

#ifndef PROTOBUF_improbable_2fgraphtier_2fNetworkCommands_2eproto__INCLUDED
#define PROTOBUF_improbable_2fgraphtier_2fNetworkCommands_2eproto__INCLUDED

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
#include "improbable/graphtier/GraphTierTypes.pb.h"
// @@protoc_insertion_point(includes)

namespace schema {
namespace improbable {
namespace graphtier {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
void protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto();
void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

class NetworkCommands;
class NetworkCommandsData;
class NetworkCommands_Commands;
class NetworkCommands_Events;
class NodeToNodeRequest;
class NodeToNodeResponse;

// ===================================================================

class NodeToNodeResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NodeToNodeResponse) */ {
 public:
  NodeToNodeResponse();
  virtual ~NodeToNodeResponse();

  NodeToNodeResponse(const NodeToNodeResponse& from);

  inline NodeToNodeResponse& operator=(const NodeToNodeResponse& from) {
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
  static const NodeToNodeResponse& default_instance();

  static const NodeToNodeResponse* internal_default_instance();

  void Swap(NodeToNodeResponse* other);

  // implements Message ----------------------------------------------

  inline NodeToNodeResponse* New() const { return New(NULL); }

  NodeToNodeResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NodeToNodeResponse& from);
  void MergeFrom(const NodeToNodeResponse& from);
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
  void InternalSwap(NodeToNodeResponse* other);
  void UnsafeMergeFrom(const NodeToNodeResponse& from);
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

  // optional .schema.improbable.graphtier.Path field1_path = 1;
  bool has_field1_path() const;
  void clear_field1_path();
  static const int kField1PathFieldNumber = 1;
  const ::schema::improbable::graphtier::Path& field1_path() const;
  ::schema::improbable::graphtier::Path* mutable_field1_path();
  ::schema::improbable::graphtier::Path* release_field1_path();
  void set_allocated_field1_path(::schema::improbable::graphtier::Path* field1_path);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NodeToNodeResponse)
 private:
  inline void set_has_field1_path();
  inline void clear_has_field1_path();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::schema::improbable::graphtier::Path* field1_path_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NodeToNodeResponse> NodeToNodeResponse_default_instance_;

// -------------------------------------------------------------------

class NodeToNodeRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NodeToNodeRequest) */ {
 public:
  NodeToNodeRequest();
  virtual ~NodeToNodeRequest();

  NodeToNodeRequest(const NodeToNodeRequest& from);

  inline NodeToNodeRequest& operator=(const NodeToNodeRequest& from) {
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
  static const NodeToNodeRequest& default_instance();

  static const NodeToNodeRequest* internal_default_instance();

  void Swap(NodeToNodeRequest* other);

  // implements Message ----------------------------------------------

  inline NodeToNodeRequest* New() const { return New(NULL); }

  NodeToNodeRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NodeToNodeRequest& from);
  void MergeFrom(const NodeToNodeRequest& from);
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
  void InternalSwap(NodeToNodeRequest* other);
  void UnsafeMergeFrom(const NodeToNodeRequest& from);
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

  // optional int64 field1_from = 1;
  bool has_field1_from() const;
  void clear_field1_from();
  static const int kField1FromFieldNumber = 1;
  ::google::protobuf::int64 field1_from() const;
  void set_field1_from(::google::protobuf::int64 value);

  // optional int64 field2_to = 2;
  bool has_field2_to() const;
  void clear_field2_to();
  static const int kField2ToFieldNumber = 2;
  ::google::protobuf::int64 field2_to() const;
  void set_field2_to(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NodeToNodeRequest)
 private:
  inline void set_has_field1_from();
  inline void clear_has_field1_from();
  inline void set_has_field2_to();
  inline void clear_has_field2_to();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int64 field1_from_;
  ::google::protobuf::int64 field2_to_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NodeToNodeRequest> NodeToNodeRequest_default_instance_;

// -------------------------------------------------------------------

class NetworkCommandsData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkCommandsData) */ {
 public:
  NetworkCommandsData();
  virtual ~NetworkCommandsData();

  NetworkCommandsData(const NetworkCommandsData& from);

  inline NetworkCommandsData& operator=(const NetworkCommandsData& from) {
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
  static const NetworkCommandsData& default_instance();

  static const NetworkCommandsData* internal_default_instance();

  void Swap(NetworkCommandsData* other);

  // implements Message ----------------------------------------------

  inline NetworkCommandsData* New() const { return New(NULL); }

  NetworkCommandsData* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkCommandsData& from);
  void MergeFrom(const NetworkCommandsData& from);
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
  void InternalSwap(NetworkCommandsData* other);
  void UnsafeMergeFrom(const NetworkCommandsData& from);
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

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkCommandsData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkCommandsData> NetworkCommandsData_default_instance_;

// -------------------------------------------------------------------

class NetworkCommands_Events : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkCommands.Events) */ {
 public:
  NetworkCommands_Events();
  virtual ~NetworkCommands_Events();

  NetworkCommands_Events(const NetworkCommands_Events& from);

  inline NetworkCommands_Events& operator=(const NetworkCommands_Events& from) {
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
  static const NetworkCommands_Events& default_instance();

  static const NetworkCommands_Events* internal_default_instance();

  void Swap(NetworkCommands_Events* other);

  // implements Message ----------------------------------------------

  inline NetworkCommands_Events* New() const { return New(NULL); }

  NetworkCommands_Events* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkCommands_Events& from);
  void MergeFrom(const NetworkCommands_Events& from);
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
  void InternalSwap(NetworkCommands_Events* other);
  void UnsafeMergeFrom(const NetworkCommands_Events& from);
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

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkCommands.Events)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkCommands_Events> NetworkCommands_Events_default_instance_;

// -------------------------------------------------------------------

class NetworkCommands_Commands : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkCommands.Commands) */ {
 public:
  NetworkCommands_Commands();
  virtual ~NetworkCommands_Commands();

  NetworkCommands_Commands(const NetworkCommands_Commands& from);

  inline NetworkCommands_Commands& operator=(const NetworkCommands_Commands& from) {
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
  static const NetworkCommands_Commands& default_instance();

  static const NetworkCommands_Commands* internal_default_instance();

  void Swap(NetworkCommands_Commands* other);

  // implements Message ----------------------------------------------

  inline NetworkCommands_Commands* New() const { return New(NULL); }

  NetworkCommands_Commands* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkCommands_Commands& from);
  void MergeFrom(const NetworkCommands_Commands& from);
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
  void InternalSwap(NetworkCommands_Commands* other);
  void UnsafeMergeFrom(const NetworkCommands_Commands& from);
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

  // optional .schema.improbable.graphtier.NodeToNodeRequest command_node_to_node_request = 1;
  bool has_command_node_to_node_request() const;
  void clear_command_node_to_node_request();
  static const int kCommandNodeToNodeRequestFieldNumber = 1;
  const ::schema::improbable::graphtier::NodeToNodeRequest& command_node_to_node_request() const;
  ::schema::improbable::graphtier::NodeToNodeRequest* mutable_command_node_to_node_request();
  ::schema::improbable::graphtier::NodeToNodeRequest* release_command_node_to_node_request();
  void set_allocated_command_node_to_node_request(::schema::improbable::graphtier::NodeToNodeRequest* command_node_to_node_request);

  // optional .schema.improbable.graphtier.NodeToNodeResponse command_node_to_node_response = 2;
  bool has_command_node_to_node_response() const;
  void clear_command_node_to_node_response();
  static const int kCommandNodeToNodeResponseFieldNumber = 2;
  const ::schema::improbable::graphtier::NodeToNodeResponse& command_node_to_node_response() const;
  ::schema::improbable::graphtier::NodeToNodeResponse* mutable_command_node_to_node_response();
  ::schema::improbable::graphtier::NodeToNodeResponse* release_command_node_to_node_response();
  void set_allocated_command_node_to_node_response(::schema::improbable::graphtier::NodeToNodeResponse* command_node_to_node_response);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkCommands.Commands)
 private:
  inline void set_has_command_node_to_node_request();
  inline void clear_has_command_node_to_node_request();
  inline void set_has_command_node_to_node_response();
  inline void clear_has_command_node_to_node_response();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::schema::improbable::graphtier::NodeToNodeRequest* command_node_to_node_request_;
  ::schema::improbable::graphtier::NodeToNodeResponse* command_node_to_node_response_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkCommands_Commands> NetworkCommands_Commands_default_instance_;

// -------------------------------------------------------------------

class NetworkCommands : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkCommands) */ {
 public:
  NetworkCommands();
  virtual ~NetworkCommands();

  NetworkCommands(const NetworkCommands& from);

  inline NetworkCommands& operator=(const NetworkCommands& from) {
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
  static const NetworkCommands& default_instance();

  static const NetworkCommands* internal_default_instance();

  void Swap(NetworkCommands* other);

  // implements Message ----------------------------------------------

  inline NetworkCommands* New() const { return New(NULL); }

  NetworkCommands* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkCommands& from);
  void MergeFrom(const NetworkCommands& from);
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
  void InternalSwap(NetworkCommands* other);
  void UnsafeMergeFrom(const NetworkCommands& from);
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

  typedef NetworkCommands_Events Events;
  typedef NetworkCommands_Commands Commands;

  // accessors -------------------------------------------------------

  static const int kComponentExtensionFieldNumber = 8001;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityState,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkCommandsData >, 11, false >
    component_extension;
  static const int kEventExtensionFieldNumber = 8001;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityEvent,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkCommands_Events >, 11, false >
    event_extension;
  static const int kCommandExtensionFieldNumber = 8001;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityCommand,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkCommands_Commands >, 11, false >
    command_extension;
  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkCommands)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkCommands_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkCommands_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkCommands> NetworkCommands_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// NodeToNodeResponse

// optional .schema.improbable.graphtier.Path field1_path = 1;
inline bool NodeToNodeResponse::has_field1_path() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NodeToNodeResponse::set_has_field1_path() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NodeToNodeResponse::clear_has_field1_path() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NodeToNodeResponse::clear_field1_path() {
  if (field1_path_ != NULL) field1_path_->::schema::improbable::graphtier::Path::Clear();
  clear_has_field1_path();
}
inline const ::schema::improbable::graphtier::Path& NodeToNodeResponse::field1_path() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NodeToNodeResponse.field1_path)
  return field1_path_ != NULL ? *field1_path_
                         : *::schema::improbable::graphtier::Path::internal_default_instance();
}
inline ::schema::improbable::graphtier::Path* NodeToNodeResponse::mutable_field1_path() {
  set_has_field1_path();
  if (field1_path_ == NULL) {
    field1_path_ = new ::schema::improbable::graphtier::Path;
  }
  // @@protoc_insertion_point(field_mutable:schema.improbable.graphtier.NodeToNodeResponse.field1_path)
  return field1_path_;
}
inline ::schema::improbable::graphtier::Path* NodeToNodeResponse::release_field1_path() {
  // @@protoc_insertion_point(field_release:schema.improbable.graphtier.NodeToNodeResponse.field1_path)
  clear_has_field1_path();
  ::schema::improbable::graphtier::Path* temp = field1_path_;
  field1_path_ = NULL;
  return temp;
}
inline void NodeToNodeResponse::set_allocated_field1_path(::schema::improbable::graphtier::Path* field1_path) {
  delete field1_path_;
  field1_path_ = field1_path;
  if (field1_path) {
    set_has_field1_path();
  } else {
    clear_has_field1_path();
  }
  // @@protoc_insertion_point(field_set_allocated:schema.improbable.graphtier.NodeToNodeResponse.field1_path)
}

inline const NodeToNodeResponse* NodeToNodeResponse::internal_default_instance() {
  return &NodeToNodeResponse_default_instance_.get();
}
// -------------------------------------------------------------------

// NodeToNodeRequest

// optional int64 field1_from = 1;
inline bool NodeToNodeRequest::has_field1_from() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NodeToNodeRequest::set_has_field1_from() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NodeToNodeRequest::clear_has_field1_from() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NodeToNodeRequest::clear_field1_from() {
  field1_from_ = GOOGLE_LONGLONG(0);
  clear_has_field1_from();
}
inline ::google::protobuf::int64 NodeToNodeRequest::field1_from() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NodeToNodeRequest.field1_from)
  return field1_from_;
}
inline void NodeToNodeRequest::set_field1_from(::google::protobuf::int64 value) {
  set_has_field1_from();
  field1_from_ = value;
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.NodeToNodeRequest.field1_from)
}

// optional int64 field2_to = 2;
inline bool NodeToNodeRequest::has_field2_to() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NodeToNodeRequest::set_has_field2_to() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NodeToNodeRequest::clear_has_field2_to() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NodeToNodeRequest::clear_field2_to() {
  field2_to_ = GOOGLE_LONGLONG(0);
  clear_has_field2_to();
}
inline ::google::protobuf::int64 NodeToNodeRequest::field2_to() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NodeToNodeRequest.field2_to)
  return field2_to_;
}
inline void NodeToNodeRequest::set_field2_to(::google::protobuf::int64 value) {
  set_has_field2_to();
  field2_to_ = value;
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.NodeToNodeRequest.field2_to)
}

inline const NodeToNodeRequest* NodeToNodeRequest::internal_default_instance() {
  return &NodeToNodeRequest_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkCommandsData

inline const NetworkCommandsData* NetworkCommandsData::internal_default_instance() {
  return &NetworkCommandsData_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkCommands_Events

inline const NetworkCommands_Events* NetworkCommands_Events::internal_default_instance() {
  return &NetworkCommands_Events_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkCommands_Commands

// optional .schema.improbable.graphtier.NodeToNodeRequest command_node_to_node_request = 1;
inline bool NetworkCommands_Commands::has_command_node_to_node_request() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetworkCommands_Commands::set_has_command_node_to_node_request() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetworkCommands_Commands::clear_has_command_node_to_node_request() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetworkCommands_Commands::clear_command_node_to_node_request() {
  if (command_node_to_node_request_ != NULL) command_node_to_node_request_->::schema::improbable::graphtier::NodeToNodeRequest::Clear();
  clear_has_command_node_to_node_request();
}
inline const ::schema::improbable::graphtier::NodeToNodeRequest& NetworkCommands_Commands::command_node_to_node_request() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_request)
  return command_node_to_node_request_ != NULL ? *command_node_to_node_request_
                         : *::schema::improbable::graphtier::NodeToNodeRequest::internal_default_instance();
}
inline ::schema::improbable::graphtier::NodeToNodeRequest* NetworkCommands_Commands::mutable_command_node_to_node_request() {
  set_has_command_node_to_node_request();
  if (command_node_to_node_request_ == NULL) {
    command_node_to_node_request_ = new ::schema::improbable::graphtier::NodeToNodeRequest;
  }
  // @@protoc_insertion_point(field_mutable:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_request)
  return command_node_to_node_request_;
}
inline ::schema::improbable::graphtier::NodeToNodeRequest* NetworkCommands_Commands::release_command_node_to_node_request() {
  // @@protoc_insertion_point(field_release:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_request)
  clear_has_command_node_to_node_request();
  ::schema::improbable::graphtier::NodeToNodeRequest* temp = command_node_to_node_request_;
  command_node_to_node_request_ = NULL;
  return temp;
}
inline void NetworkCommands_Commands::set_allocated_command_node_to_node_request(::schema::improbable::graphtier::NodeToNodeRequest* command_node_to_node_request) {
  delete command_node_to_node_request_;
  command_node_to_node_request_ = command_node_to_node_request;
  if (command_node_to_node_request) {
    set_has_command_node_to_node_request();
  } else {
    clear_has_command_node_to_node_request();
  }
  // @@protoc_insertion_point(field_set_allocated:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_request)
}

// optional .schema.improbable.graphtier.NodeToNodeResponse command_node_to_node_response = 2;
inline bool NetworkCommands_Commands::has_command_node_to_node_response() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NetworkCommands_Commands::set_has_command_node_to_node_response() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NetworkCommands_Commands::clear_has_command_node_to_node_response() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NetworkCommands_Commands::clear_command_node_to_node_response() {
  if (command_node_to_node_response_ != NULL) command_node_to_node_response_->::schema::improbable::graphtier::NodeToNodeResponse::Clear();
  clear_has_command_node_to_node_response();
}
inline const ::schema::improbable::graphtier::NodeToNodeResponse& NetworkCommands_Commands::command_node_to_node_response() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_response)
  return command_node_to_node_response_ != NULL ? *command_node_to_node_response_
                         : *::schema::improbable::graphtier::NodeToNodeResponse::internal_default_instance();
}
inline ::schema::improbable::graphtier::NodeToNodeResponse* NetworkCommands_Commands::mutable_command_node_to_node_response() {
  set_has_command_node_to_node_response();
  if (command_node_to_node_response_ == NULL) {
    command_node_to_node_response_ = new ::schema::improbable::graphtier::NodeToNodeResponse;
  }
  // @@protoc_insertion_point(field_mutable:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_response)
  return command_node_to_node_response_;
}
inline ::schema::improbable::graphtier::NodeToNodeResponse* NetworkCommands_Commands::release_command_node_to_node_response() {
  // @@protoc_insertion_point(field_release:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_response)
  clear_has_command_node_to_node_response();
  ::schema::improbable::graphtier::NodeToNodeResponse* temp = command_node_to_node_response_;
  command_node_to_node_response_ = NULL;
  return temp;
}
inline void NetworkCommands_Commands::set_allocated_command_node_to_node_response(::schema::improbable::graphtier::NodeToNodeResponse* command_node_to_node_response) {
  delete command_node_to_node_response_;
  command_node_to_node_response_ = command_node_to_node_response;
  if (command_node_to_node_response) {
    set_has_command_node_to_node_response();
  } else {
    clear_has_command_node_to_node_response();
  }
  // @@protoc_insertion_point(field_set_allocated:schema.improbable.graphtier.NetworkCommands.Commands.command_node_to_node_response)
}

inline const NetworkCommands_Commands* NetworkCommands_Commands::internal_default_instance() {
  return &NetworkCommands_Commands_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkCommands

inline const NetworkCommands* NetworkCommands::internal_default_instance() {
  return &NetworkCommands_default_instance_.get();
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

#endif  // PROTOBUF_improbable_2fgraphtier_2fNetworkCommands_2eproto__INCLUDED
