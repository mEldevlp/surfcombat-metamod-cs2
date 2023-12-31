// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: uifontfile_format.proto

#include "uifontfile_format.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR CUIFontFilePB::CUIFontFilePB(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.font_file_name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.opentype_font_data_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}} {}
struct CUIFontFilePBDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CUIFontFilePBDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CUIFontFilePBDefaultTypeInternal() {}
  union {
    CUIFontFilePB _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CUIFontFilePBDefaultTypeInternal _CUIFontFilePB_default_instance_;
PROTOBUF_CONSTEXPR CUIFontFilePackagePB_CUIEncryptedFontFilePB::CUIFontFilePackagePB_CUIEncryptedFontFilePB(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.encrypted_contents_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}} {}
struct CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal() {}
  union {
    CUIFontFilePackagePB_CUIEncryptedFontFilePB _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CUIFontFilePackagePB_CUIEncryptedFontFilePBDefaultTypeInternal _CUIFontFilePackagePB_CUIEncryptedFontFilePB_default_instance_;
PROTOBUF_CONSTEXPR CUIFontFilePackagePB::CUIFontFilePackagePB(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.encrypted_font_files_)*/{}
  , /*decltype(_impl_.package_version_)*/0u} {}
struct CUIFontFilePackagePBDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CUIFontFilePackagePBDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CUIFontFilePackagePBDefaultTypeInternal() {}
  union {
    CUIFontFilePackagePB _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CUIFontFilePackagePBDefaultTypeInternal _CUIFontFilePackagePB_default_instance_;
static ::_pb::Metadata file_level_metadata_uifontfile_5fformat_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_uifontfile_5fformat_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_uifontfile_5fformat_2eproto = nullptr;

const uint32_t TableStruct_uifontfile_5fformat_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _impl_.font_file_name_),
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePB, _impl_.opentype_font_data_),
  0,
  1,
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB_CUIEncryptedFontFilePB, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB_CUIEncryptedFontFilePB, _impl_.encrypted_contents_),
  0,
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _impl_.package_version_),
  PROTOBUF_FIELD_OFFSET(::CUIFontFilePackagePB, _impl_.encrypted_font_files_),
  0,
  ~0u,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, -1, sizeof(::CUIFontFilePB)},
  { 10, 17, -1, sizeof(::CUIFontFilePackagePB_CUIEncryptedFontFilePB)},
  { 18, 26, -1, sizeof(::CUIFontFilePackagePB)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_CUIFontFilePB_default_instance_._instance,
  &::_CUIFontFilePackagePB_CUIEncryptedFontFilePB_default_instance_._instance,
  &::_CUIFontFilePackagePB_default_instance_._instance,
};

const char descriptor_table_protodef_uifontfile_5fformat_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\027uifontfile_format.proto\"C\n\rCUIFontFile"
  "PB\022\026\n\016font_file_name\030\001 \001(\t\022\032\n\022opentype_f"
  "ont_data\030\002 \001(\014\"\261\001\n\024CUIFontFilePackagePB\022"
  "\027\n\017package_version\030\001 \002(\r\022J\n\024encrypted_fo"
  "nt_files\030\002 \003(\0132,.CUIFontFilePackagePB.CU"
  "IEncryptedFontFilePB\0324\n\026CUIEncryptedFont"
  "FilePB\022\032\n\022encrypted_contents\030\001 \001(\014"
  ;
static ::_pbi::once_flag descriptor_table_uifontfile_5fformat_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_uifontfile_5fformat_2eproto = {
    false, false, 274, descriptor_table_protodef_uifontfile_5fformat_2eproto,
    "uifontfile_format.proto",
    &descriptor_table_uifontfile_5fformat_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_uifontfile_5fformat_2eproto::offsets,
    file_level_metadata_uifontfile_5fformat_2eproto, file_level_enum_descriptors_uifontfile_5fformat_2eproto,
    file_level_service_descriptors_uifontfile_5fformat_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_uifontfile_5fformat_2eproto_getter() {
  return &descriptor_table_uifontfile_5fformat_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_uifontfile_5fformat_2eproto(&descriptor_table_uifontfile_5fformat_2eproto);

// ===================================================================

class CUIFontFilePB::_Internal {
 public:
  using HasBits = decltype(std::declval<CUIFontFilePB>()._impl_._has_bits_);
  static void set_has_font_file_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_opentype_font_data(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

CUIFontFilePB::CUIFontFilePB(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:CUIFontFilePB)
}
CUIFontFilePB::CUIFontFilePB(const CUIFontFilePB& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CUIFontFilePB* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.font_file_name_){}
    , decltype(_impl_.opentype_font_data_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.font_file_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.font_file_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_font_file_name()) {
    _this->_impl_.font_file_name_.Set(from._internal_font_file_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.opentype_font_data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.opentype_font_data_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_opentype_font_data()) {
    _this->_impl_.opentype_font_data_.Set(from._internal_opentype_font_data(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:CUIFontFilePB)
}

inline void CUIFontFilePB::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.font_file_name_){}
    , decltype(_impl_.opentype_font_data_){}
  };
  _impl_.font_file_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.font_file_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.opentype_font_data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.opentype_font_data_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

CUIFontFilePB::~CUIFontFilePB() {
  // @@protoc_insertion_point(destructor:CUIFontFilePB)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CUIFontFilePB::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.font_file_name_.Destroy();
  _impl_.opentype_font_data_.Destroy();
}

void CUIFontFilePB::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CUIFontFilePB::Clear() {
// @@protoc_insertion_point(message_clear_start:CUIFontFilePB)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.font_file_name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.opentype_font_data_.ClearNonDefaultToEmpty();
    }
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CUIFontFilePB::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional string font_file_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_font_file_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          #ifndef NDEBUG
          ::_pbi::VerifyUTF8(str, "CUIFontFilePB.font_file_name");
          #endif  // !NDEBUG
        } else
          goto handle_unusual;
        continue;
      // optional bytes opentype_font_data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_opentype_font_data();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CUIFontFilePB::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CUIFontFilePB)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional string font_file_name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_font_file_name().data(), static_cast<int>(this->_internal_font_file_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "CUIFontFilePB.font_file_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_font_file_name(), target);
  }

  // optional bytes opentype_font_data = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_opentype_font_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CUIFontFilePB)
  return target;
}

size_t CUIFontFilePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CUIFontFilePB)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string font_file_name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_font_file_name());
    }

    // optional bytes opentype_font_data = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_opentype_font_data());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CUIFontFilePB::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CUIFontFilePB::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CUIFontFilePB::GetClassData() const { return &_class_data_; }


void CUIFontFilePB::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CUIFontFilePB*>(&to_msg);
  auto& from = static_cast<const CUIFontFilePB&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CUIFontFilePB)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_font_file_name(from._internal_font_file_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_set_opentype_font_data(from._internal_opentype_font_data());
    }
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CUIFontFilePB::CopyFrom(const CUIFontFilePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CUIFontFilePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CUIFontFilePB::IsInitialized() const {
  return true;
}

void CUIFontFilePB::InternalSwap(CUIFontFilePB* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.font_file_name_, lhs_arena,
      &other->_impl_.font_file_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.opentype_font_data_, lhs_arena,
      &other->_impl_.opentype_font_data_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata CUIFontFilePB::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_uifontfile_5fformat_2eproto_getter, &descriptor_table_uifontfile_5fformat_2eproto_once,
      file_level_metadata_uifontfile_5fformat_2eproto[0]);
}

// ===================================================================

class CUIFontFilePackagePB_CUIEncryptedFontFilePB::_Internal {
 public:
  using HasBits = decltype(std::declval<CUIFontFilePackagePB_CUIEncryptedFontFilePB>()._impl_._has_bits_);
  static void set_has_encrypted_contents(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CUIFontFilePackagePB_CUIEncryptedFontFilePB::CUIFontFilePackagePB_CUIEncryptedFontFilePB(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
}
CUIFontFilePackagePB_CUIEncryptedFontFilePB::CUIFontFilePackagePB_CUIEncryptedFontFilePB(const CUIFontFilePackagePB_CUIEncryptedFontFilePB& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CUIFontFilePackagePB_CUIEncryptedFontFilePB* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.encrypted_contents_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.encrypted_contents_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.encrypted_contents_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_encrypted_contents()) {
    _this->_impl_.encrypted_contents_.Set(from._internal_encrypted_contents(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
}

inline void CUIFontFilePackagePB_CUIEncryptedFontFilePB::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.encrypted_contents_){}
  };
  _impl_.encrypted_contents_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.encrypted_contents_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

CUIFontFilePackagePB_CUIEncryptedFontFilePB::~CUIFontFilePackagePB_CUIEncryptedFontFilePB() {
  // @@protoc_insertion_point(destructor:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CUIFontFilePackagePB_CUIEncryptedFontFilePB::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.encrypted_contents_.Destroy();
}

void CUIFontFilePackagePB_CUIEncryptedFontFilePB::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CUIFontFilePackagePB_CUIEncryptedFontFilePB::Clear() {
// @@protoc_insertion_point(message_clear_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.encrypted_contents_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CUIFontFilePackagePB_CUIEncryptedFontFilePB::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional bytes encrypted_contents = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_encrypted_contents();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CUIFontFilePackagePB_CUIEncryptedFontFilePB::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional bytes encrypted_contents = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_encrypted_contents(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  return target;
}

size_t CUIFontFilePackagePB_CUIEncryptedFontFilePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional bytes encrypted_contents = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_encrypted_contents());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CUIFontFilePackagePB_CUIEncryptedFontFilePB::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CUIFontFilePackagePB_CUIEncryptedFontFilePB::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CUIFontFilePackagePB_CUIEncryptedFontFilePB::GetClassData() const { return &_class_data_; }


void CUIFontFilePackagePB_CUIEncryptedFontFilePB::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CUIFontFilePackagePB_CUIEncryptedFontFilePB*>(&to_msg);
  auto& from = static_cast<const CUIFontFilePackagePB_CUIEncryptedFontFilePB&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_encrypted_contents()) {
    _this->_internal_set_encrypted_contents(from._internal_encrypted_contents());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CUIFontFilePackagePB_CUIEncryptedFontFilePB::CopyFrom(const CUIFontFilePackagePB_CUIEncryptedFontFilePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CUIFontFilePackagePB.CUIEncryptedFontFilePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CUIFontFilePackagePB_CUIEncryptedFontFilePB::IsInitialized() const {
  return true;
}

void CUIFontFilePackagePB_CUIEncryptedFontFilePB::InternalSwap(CUIFontFilePackagePB_CUIEncryptedFontFilePB* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.encrypted_contents_, lhs_arena,
      &other->_impl_.encrypted_contents_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata CUIFontFilePackagePB_CUIEncryptedFontFilePB::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_uifontfile_5fformat_2eproto_getter, &descriptor_table_uifontfile_5fformat_2eproto_once,
      file_level_metadata_uifontfile_5fformat_2eproto[1]);
}

// ===================================================================

class CUIFontFilePackagePB::_Internal {
 public:
  using HasBits = decltype(std::declval<CUIFontFilePackagePB>()._impl_._has_bits_);
  static void set_has_package_version(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000001) ^ 0x00000001) != 0;
  }
};

CUIFontFilePackagePB::CUIFontFilePackagePB(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:CUIFontFilePackagePB)
}
CUIFontFilePackagePB::CUIFontFilePackagePB(const CUIFontFilePackagePB& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CUIFontFilePackagePB* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.encrypted_font_files_){from._impl_.encrypted_font_files_}
    , decltype(_impl_.package_version_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.package_version_ = from._impl_.package_version_;
  // @@protoc_insertion_point(copy_constructor:CUIFontFilePackagePB)
}

inline void CUIFontFilePackagePB::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.encrypted_font_files_){arena}
    , decltype(_impl_.package_version_){0u}
  };
}

CUIFontFilePackagePB::~CUIFontFilePackagePB() {
  // @@protoc_insertion_point(destructor:CUIFontFilePackagePB)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CUIFontFilePackagePB::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.encrypted_font_files_.~RepeatedPtrField();
}

void CUIFontFilePackagePB::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CUIFontFilePackagePB::Clear() {
// @@protoc_insertion_point(message_clear_start:CUIFontFilePackagePB)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.encrypted_font_files_.Clear();
  _impl_.package_version_ = 0u;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CUIFontFilePackagePB::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required uint32 package_version = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _Internal::set_has_package_version(&has_bits);
          _impl_.package_version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_encrypted_font_files(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CUIFontFilePackagePB::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CUIFontFilePackagePB)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // required uint32 package_version = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_package_version(), target);
  }

  // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_encrypted_font_files_size()); i < n; i++) {
    const auto& repfield = this->_internal_encrypted_font_files(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CUIFontFilePackagePB)
  return target;
}

size_t CUIFontFilePackagePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CUIFontFilePackagePB)
  size_t total_size = 0;

  // required uint32 package_version = 1;
  if (_internal_has_package_version()) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_package_version());
  }
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .CUIFontFilePackagePB.CUIEncryptedFontFilePB encrypted_font_files = 2;
  total_size += 1UL * this->_internal_encrypted_font_files_size();
  for (const auto& msg : this->_impl_.encrypted_font_files_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CUIFontFilePackagePB::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CUIFontFilePackagePB::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CUIFontFilePackagePB::GetClassData() const { return &_class_data_; }


void CUIFontFilePackagePB::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CUIFontFilePackagePB*>(&to_msg);
  auto& from = static_cast<const CUIFontFilePackagePB&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CUIFontFilePackagePB)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.encrypted_font_files_.MergeFrom(from._impl_.encrypted_font_files_);
  if (from._internal_has_package_version()) {
    _this->_internal_set_package_version(from._internal_package_version());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CUIFontFilePackagePB::CopyFrom(const CUIFontFilePackagePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CUIFontFilePackagePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CUIFontFilePackagePB::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_impl_._has_bits_)) return false;
  return true;
}

void CUIFontFilePackagePB::InternalSwap(CUIFontFilePackagePB* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.encrypted_font_files_.InternalSwap(&other->_impl_.encrypted_font_files_);
  swap(_impl_.package_version_, other->_impl_.package_version_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CUIFontFilePackagePB::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_uifontfile_5fformat_2eproto_getter, &descriptor_table_uifontfile_5fformat_2eproto_once,
      file_level_metadata_uifontfile_5fformat_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CUIFontFilePB*
Arena::CreateMaybeMessage< ::CUIFontFilePB >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CUIFontFilePB >(arena);
}
template<> PROTOBUF_NOINLINE ::CUIFontFilePackagePB_CUIEncryptedFontFilePB*
Arena::CreateMaybeMessage< ::CUIFontFilePackagePB_CUIEncryptedFontFilePB >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CUIFontFilePackagePB_CUIEncryptedFontFilePB >(arena);
}
template<> PROTOBUF_NOINLINE ::CUIFontFilePackagePB*
Arena::CreateMaybeMessage< ::CUIFontFilePackagePB >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CUIFontFilePackagePB >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
