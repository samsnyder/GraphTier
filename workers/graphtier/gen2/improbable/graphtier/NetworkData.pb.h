// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: improbable/graphtier/NetworkData.proto

#ifndef PROTOBUF_improbable_2fgraphtier_2fNetworkData_2eproto__INCLUDED
#define PROTOBUF_improbable_2fgraphtier_2fNetworkData_2eproto__INCLUDED

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
void protobuf_AddDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
void protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkData_2eproto();
void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkData_2eproto();

class ExitNodeSet;
class NetworkData;
class NetworkDataData;
class NetworkData_Commands;
class NetworkData_Events;

// ===================================================================

class ExitNodeSet : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.ExitNodeSet) */ {
 public:
  ExitNodeSet();
  virtual ~ExitNodeSet();

  ExitNodeSet(const ExitNodeSet& from);

  inline ExitNodeSet& operator=(const ExitNodeSet& from) {
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
  static const ExitNodeSet& default_instance();

  static const ExitNodeSet* internal_default_instance();

  void Swap(ExitNodeSet* other);

  // implements Message ----------------------------------------------

  inline ExitNodeSet* New() const { return New(NULL); }

  ExitNodeSet* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ExitNodeSet& from);
  void MergeFrom(const ExitNodeSet& from);
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
  void InternalSwap(ExitNodeSet* other);
  void UnsafeMergeFrom(const ExitNodeSet& from);
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

  // repeated int64 field1_exit_nodes = 1 [packed = true];
  int field1_exit_nodes_size() const;
  void clear_field1_exit_nodes();
  static const int kField1ExitNodesFieldNumber = 1;
  ::google::protobuf::int64 field1_exit_nodes(int index) const;
  void set_field1_exit_nodes(int index, ::google::protobuf::int64 value);
  void add_field1_exit_nodes(::google::protobuf::int64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      field1_exit_nodes() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_field1_exit_nodes();

  // optional int64 field2_network_id = 2;
  bool has_field2_network_id() const;
  void clear_field2_network_id();
  static const int kField2NetworkIdFieldNumber = 2;
  ::google::protobuf::int64 field2_network_id() const;
  void set_field2_network_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.ExitNodeSet)
 private:
  inline void set_has_field2_network_id();
  inline void clear_has_field2_network_id();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > field1_exit_nodes_;
  mutable int _field1_exit_nodes_cached_byte_size_;
  ::google::protobuf::int64 field2_network_id_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkData_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ExitNodeSet> ExitNodeSet_default_instance_;

// -------------------------------------------------------------------

class NetworkDataData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkDataData) */ {
 public:
  NetworkDataData();
  virtual ~NetworkDataData();

  NetworkDataData(const NetworkDataData& from);

  inline NetworkDataData& operator=(const NetworkDataData& from) {
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
  static const NetworkDataData& default_instance();

  static const NetworkDataData* internal_default_instance();

  void Swap(NetworkDataData* other);

  // implements Message ----------------------------------------------

  inline NetworkDataData* New() const { return New(NULL); }

  NetworkDataData* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkDataData& from);
  void MergeFrom(const NetworkDataData& from);
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
  void InternalSwap(NetworkDataData* other);
  void UnsafeMergeFrom(const NetworkDataData& from);
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

  // optional uint32 field1_level = 1;
  bool has_field1_level() const;
  void clear_field1_level();
  static const int kField1LevelFieldNumber = 1;
  ::google::protobuf::uint32 field1_level() const;
  void set_field1_level(::google::protobuf::uint32 value);

  // repeated int64 field2_nodes = 2 [packed = true];
  int field2_nodes_size() const;
  void clear_field2_nodes();
  static const int kField2NodesFieldNumber = 2;
  ::google::protobuf::int64 field2_nodes(int index) const;
  void set_field2_nodes(int index, ::google::protobuf::int64 value);
  void add_field2_nodes(::google::protobuf::int64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      field2_nodes() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_field2_nodes();

  // repeated .schema.improbable.graphtier.ExitNodeSet field3_exit_node_sets = 3;
  int field3_exit_node_sets_size() const;
  void clear_field3_exit_node_sets();
  static const int kField3ExitNodeSetsFieldNumber = 3;
  const ::schema::improbable::graphtier::ExitNodeSet& field3_exit_node_sets(int index) const;
  ::schema::improbable::graphtier::ExitNodeSet* mutable_field3_exit_node_sets(int index);
  ::schema::improbable::graphtier::ExitNodeSet* add_field3_exit_node_sets();
  ::google::protobuf::RepeatedPtrField< ::schema::improbable::graphtier::ExitNodeSet >*
      mutable_field3_exit_node_sets();
  const ::google::protobuf::RepeatedPtrField< ::schema::improbable::graphtier::ExitNodeSet >&
      field3_exit_node_sets() const;

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkDataData)
 private:
  inline void set_has_field1_level();
  inline void clear_has_field1_level();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > field2_nodes_;
  mutable int _field2_nodes_cached_byte_size_;
  ::google::protobuf::RepeatedPtrField< ::schema::improbable::graphtier::ExitNodeSet > field3_exit_node_sets_;
  ::google::protobuf::uint32 field1_level_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkData_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkDataData> NetworkDataData_default_instance_;

// -------------------------------------------------------------------

class NetworkData_Events : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkData.Events) */ {
 public:
  NetworkData_Events();
  virtual ~NetworkData_Events();

  NetworkData_Events(const NetworkData_Events& from);

  inline NetworkData_Events& operator=(const NetworkData_Events& from) {
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
  static const NetworkData_Events& default_instance();

  static const NetworkData_Events* internal_default_instance();

  void Swap(NetworkData_Events* other);

  // implements Message ----------------------------------------------

  inline NetworkData_Events* New() const { return New(NULL); }

  NetworkData_Events* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkData_Events& from);
  void MergeFrom(const NetworkData_Events& from);
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
  void InternalSwap(NetworkData_Events* other);
  void UnsafeMergeFrom(const NetworkData_Events& from);
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

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkData.Events)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkData_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkData_Events> NetworkData_Events_default_instance_;

// -------------------------------------------------------------------

class NetworkData_Commands : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkData.Commands) */ {
 public:
  NetworkData_Commands();
  virtual ~NetworkData_Commands();

  NetworkData_Commands(const NetworkData_Commands& from);

  inline NetworkData_Commands& operator=(const NetworkData_Commands& from) {
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
  static const NetworkData_Commands& default_instance();

  static const NetworkData_Commands* internal_default_instance();

  void Swap(NetworkData_Commands* other);

  // implements Message ----------------------------------------------

  inline NetworkData_Commands* New() const { return New(NULL); }

  NetworkData_Commands* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkData_Commands& from);
  void MergeFrom(const NetworkData_Commands& from);
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
  void InternalSwap(NetworkData_Commands* other);
  void UnsafeMergeFrom(const NetworkData_Commands& from);
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

  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkData.Commands)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkData_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkData_Commands> NetworkData_Commands_default_instance_;

// -------------------------------------------------------------------

class NetworkData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:schema.improbable.graphtier.NetworkData) */ {
 public:
  NetworkData();
  virtual ~NetworkData();

  NetworkData(const NetworkData& from);

  inline NetworkData& operator=(const NetworkData& from) {
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
  static const NetworkData& default_instance();

  static const NetworkData* internal_default_instance();

  void Swap(NetworkData* other);

  // implements Message ----------------------------------------------

  inline NetworkData* New() const { return New(NULL); }

  NetworkData* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetworkData& from);
  void MergeFrom(const NetworkData& from);
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
  void InternalSwap(NetworkData* other);
  void UnsafeMergeFrom(const NetworkData& from);
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

  typedef NetworkData_Events Events;
  typedef NetworkData_Commands Commands;

  // accessors -------------------------------------------------------

  static const int kComponentExtensionFieldNumber = 8002;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityState,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkDataData >, 11, false >
    component_extension;
  static const int kEventExtensionFieldNumber = 8002;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityEvent,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkData_Events >, 11, false >
    event_extension;
  static const int kCommandExtensionFieldNumber = 8002;
  static ::google::protobuf::internal::ExtensionIdentifier< ::schema::improbable::EntityCommand,
      ::google::protobuf::internal::MessageTypeTraits< ::schema::improbable::graphtier::NetworkData_Commands >, 11, false >
    command_extension;
  // @@protoc_insertion_point(class_scope:schema.improbable.graphtier.NetworkData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void  protobuf_AddDesc_improbable_2fgraphtier_2fNetworkData_2eproto_impl();
  friend void protobuf_AssignDesc_improbable_2fgraphtier_2fNetworkData_2eproto();
  friend void protobuf_ShutdownFile_improbable_2fgraphtier_2fNetworkData_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<NetworkData> NetworkData_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ExitNodeSet

// repeated int64 field1_exit_nodes = 1 [packed = true];
inline int ExitNodeSet::field1_exit_nodes_size() const {
  return field1_exit_nodes_.size();
}
inline void ExitNodeSet::clear_field1_exit_nodes() {
  field1_exit_nodes_.Clear();
}
inline ::google::protobuf::int64 ExitNodeSet::field1_exit_nodes(int index) const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.ExitNodeSet.field1_exit_nodes)
  return field1_exit_nodes_.Get(index);
}
inline void ExitNodeSet::set_field1_exit_nodes(int index, ::google::protobuf::int64 value) {
  field1_exit_nodes_.Set(index, value);
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.ExitNodeSet.field1_exit_nodes)
}
inline void ExitNodeSet::add_field1_exit_nodes(::google::protobuf::int64 value) {
  field1_exit_nodes_.Add(value);
  // @@protoc_insertion_point(field_add:schema.improbable.graphtier.ExitNodeSet.field1_exit_nodes)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ExitNodeSet::field1_exit_nodes() const {
  // @@protoc_insertion_point(field_list:schema.improbable.graphtier.ExitNodeSet.field1_exit_nodes)
  return field1_exit_nodes_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ExitNodeSet::mutable_field1_exit_nodes() {
  // @@protoc_insertion_point(field_mutable_list:schema.improbable.graphtier.ExitNodeSet.field1_exit_nodes)
  return &field1_exit_nodes_;
}

// optional int64 field2_network_id = 2;
inline bool ExitNodeSet::has_field2_network_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ExitNodeSet::set_has_field2_network_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ExitNodeSet::clear_has_field2_network_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ExitNodeSet::clear_field2_network_id() {
  field2_network_id_ = GOOGLE_LONGLONG(0);
  clear_has_field2_network_id();
}
inline ::google::protobuf::int64 ExitNodeSet::field2_network_id() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.ExitNodeSet.field2_network_id)
  return field2_network_id_;
}
inline void ExitNodeSet::set_field2_network_id(::google::protobuf::int64 value) {
  set_has_field2_network_id();
  field2_network_id_ = value;
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.ExitNodeSet.field2_network_id)
}

inline const ExitNodeSet* ExitNodeSet::internal_default_instance() {
  return &ExitNodeSet_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkDataData

// optional uint32 field1_level = 1;
inline bool NetworkDataData::has_field1_level() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetworkDataData::set_has_field1_level() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetworkDataData::clear_has_field1_level() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetworkDataData::clear_field1_level() {
  field1_level_ = 0u;
  clear_has_field1_level();
}
inline ::google::protobuf::uint32 NetworkDataData::field1_level() const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkDataData.field1_level)
  return field1_level_;
}
inline void NetworkDataData::set_field1_level(::google::protobuf::uint32 value) {
  set_has_field1_level();
  field1_level_ = value;
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.NetworkDataData.field1_level)
}

// repeated int64 field2_nodes = 2 [packed = true];
inline int NetworkDataData::field2_nodes_size() const {
  return field2_nodes_.size();
}
inline void NetworkDataData::clear_field2_nodes() {
  field2_nodes_.Clear();
}
inline ::google::protobuf::int64 NetworkDataData::field2_nodes(int index) const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkDataData.field2_nodes)
  return field2_nodes_.Get(index);
}
inline void NetworkDataData::set_field2_nodes(int index, ::google::protobuf::int64 value) {
  field2_nodes_.Set(index, value);
  // @@protoc_insertion_point(field_set:schema.improbable.graphtier.NetworkDataData.field2_nodes)
}
inline void NetworkDataData::add_field2_nodes(::google::protobuf::int64 value) {
  field2_nodes_.Add(value);
  // @@protoc_insertion_point(field_add:schema.improbable.graphtier.NetworkDataData.field2_nodes)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
NetworkDataData::field2_nodes() const {
  // @@protoc_insertion_point(field_list:schema.improbable.graphtier.NetworkDataData.field2_nodes)
  return field2_nodes_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
NetworkDataData::mutable_field2_nodes() {
  // @@protoc_insertion_point(field_mutable_list:schema.improbable.graphtier.NetworkDataData.field2_nodes)
  return &field2_nodes_;
}

// repeated .schema.improbable.graphtier.ExitNodeSet field3_exit_node_sets = 3;
inline int NetworkDataData::field3_exit_node_sets_size() const {
  return field3_exit_node_sets_.size();
}
inline void NetworkDataData::clear_field3_exit_node_sets() {
  field3_exit_node_sets_.Clear();
}
inline const ::schema::improbable::graphtier::ExitNodeSet& NetworkDataData::field3_exit_node_sets(int index) const {
  // @@protoc_insertion_point(field_get:schema.improbable.graphtier.NetworkDataData.field3_exit_node_sets)
  return field3_exit_node_sets_.Get(index);
}
inline ::schema::improbable::graphtier::ExitNodeSet* NetworkDataData::mutable_field3_exit_node_sets(int index) {
  // @@protoc_insertion_point(field_mutable:schema.improbable.graphtier.NetworkDataData.field3_exit_node_sets)
  return field3_exit_node_sets_.Mutable(index);
}
inline ::schema::improbable::graphtier::ExitNodeSet* NetworkDataData::add_field3_exit_node_sets() {
  // @@protoc_insertion_point(field_add:schema.improbable.graphtier.NetworkDataData.field3_exit_node_sets)
  return field3_exit_node_sets_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::schema::improbable::graphtier::ExitNodeSet >*
NetworkDataData::mutable_field3_exit_node_sets() {
  // @@protoc_insertion_point(field_mutable_list:schema.improbable.graphtier.NetworkDataData.field3_exit_node_sets)
  return &field3_exit_node_sets_;
}
inline const ::google::protobuf::RepeatedPtrField< ::schema::improbable::graphtier::ExitNodeSet >&
NetworkDataData::field3_exit_node_sets() const {
  // @@protoc_insertion_point(field_list:schema.improbable.graphtier.NetworkDataData.field3_exit_node_sets)
  return field3_exit_node_sets_;
}

inline const NetworkDataData* NetworkDataData::internal_default_instance() {
  return &NetworkDataData_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkData_Events

inline const NetworkData_Events* NetworkData_Events::internal_default_instance() {
  return &NetworkData_Events_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkData_Commands

inline const NetworkData_Commands* NetworkData_Commands::internal_default_instance() {
  return &NetworkData_Commands_default_instance_.get();
}
// -------------------------------------------------------------------

// NetworkData

inline const NetworkData* NetworkData::internal_default_instance() {
  return &NetworkData_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace graphtier
}  // namespace improbable
}  // namespace schema

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_improbable_2fgraphtier_2fNetworkData_2eproto__INCLUDED
