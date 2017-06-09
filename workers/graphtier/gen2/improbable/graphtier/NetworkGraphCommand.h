// Generated by SpatialOS codegen. DO NOT EDIT!
// source: improbable/graphtier/NetworkGraphCommand.schema
#ifndef SPATIALOS_SCHEMA_improbable_graphtier_NetworkGraphCommand_schema_9461584695049045978_INCLUDED
#define SPATIALOS_SCHEMA_improbable_graphtier_NetworkGraphCommand_schema_9461584695049045978_INCLUDED
#include <improbable/collections.h>
#include <improbable/math/coordinates.h>
#include <improbable/math/vector3d.h>
#include <improbable/math/vector3f.h>
#include <improbable/worker.h>
#include <cstddef>
#include <cstdint>
#include <set>
#include <string>

// Schema forward declarations.
//----------------------------------------------------------------

namespace schema {
namespace improbable {
namespace graphtier {

class NetworkGraphResponse;
class NetworkGraphRequest;
class NetworkGraphCommandData;

}  // ::improbable
}  // ::graphtier
}  // ::schema

namespace improbable {
namespace graphtier {

// Forward declarations.
//----------------------------------------------------------------

class NetworkGraphCommandData;
class NetworkGraphRequest;
class NetworkGraphResponse;

namespace detail {
const ::worker::detail::ClientComponentVtable& Vtable_NetworkGraphCommand();
struct GenericCommandObject_NetworkGraphCommand {
  std::uint32_t CommandId;
  ::worker::Variant<
      ::improbable::graphtier::NetworkGraphRequest,
      ::improbable::graphtier::NetworkGraphResponse> CommandObject;
};
}  // ::detail

// Enumerations.
//----------------------------------------------------------------

// Data classes.
//----------------------------------------------------------------

class NetworkGraphCommandData {
public:
  // Main constructor.
  NetworkGraphCommandData();

  // Copyable and moveable.
  NetworkGraphCommandData(NetworkGraphCommandData&&) = default;
  NetworkGraphCommandData(const NetworkGraphCommandData&) = default;
  NetworkGraphCommandData& operator=(NetworkGraphCommandData&&) = default;
  NetworkGraphCommandData& operator=(const NetworkGraphCommandData&) = default;
  ~NetworkGraphCommandData() = default;

  bool operator==(const NetworkGraphCommandData&) const;
  bool operator!=(const NetworkGraphCommandData&) const;
};

class NetworkGraphRequest {
public:
  // Main constructor.
  NetworkGraphRequest(::worker::EntityId target_network_id);

  // Copyable and moveable.
  NetworkGraphRequest(NetworkGraphRequest&&) = default;
  NetworkGraphRequest(const NetworkGraphRequest&) = default;
  NetworkGraphRequest& operator=(NetworkGraphRequest&&) = default;
  NetworkGraphRequest& operator=(const NetworkGraphRequest&) = default;
  ~NetworkGraphRequest() = default;

  bool operator==(const NetworkGraphRequest&) const;
  bool operator!=(const NetworkGraphRequest&) const;

  // Field target_network_id = 1.
  ::worker::EntityId target_network_id() const;
  ::worker::EntityId& target_network_id();
  NetworkGraphRequest& set_target_network_id(::worker::EntityId);

private:
  ::worker::EntityId _target_network_id;
};

class NetworkGraphResponse {
public:
  // Main constructor.
  NetworkGraphResponse(std::uint32_t data);

  // Copyable and moveable.
  NetworkGraphResponse(NetworkGraphResponse&&) = default;
  NetworkGraphResponse(const NetworkGraphResponse&) = default;
  NetworkGraphResponse& operator=(NetworkGraphResponse&&) = default;
  NetworkGraphResponse& operator=(const NetworkGraphResponse&) = default;
  ~NetworkGraphResponse() = default;

  bool operator==(const NetworkGraphResponse&) const;
  bool operator!=(const NetworkGraphResponse&) const;

  // Field data = 1.
  std::uint32_t data() const;
  std::uint32_t& data();
  NetworkGraphResponse& set_data(std::uint32_t);

private:
  std::uint32_t _data;
};

// Component metaclasses and update classes.
//----------------------------------------------------------------

/**
 * This type can be supplied as the template parameter to all component-related templated types
 * and methods in the C++ worker API. For example:
 *
 *   using ::improbable::graphtier::NetworkGraphCommand;
 *
 *   NetworkGraphCommand::Update update;
 *   connection.SendComponentUpdate< NetworkGraphCommand >(entity_id, update);
 *
 *   dispatcher.OnComponentUpdate< NetworkGraphCommand >(
 *       [&](const worker::ComponentUpdateOp< NetworkGraphCommand >& op) {
 *         worker::EntityId entity_id = op.GetEntityId();
 *         NetworkGraphCommand::Update update = op.GetUpdate();
 *       });
 *
 *   NetworkGraphCommand::Data data = entity.Get< NetworkGraphCommand >();
 */
struct NetworkGraphCommand : ::worker::detail::ComponentMetaclassBase<
    NetworkGraphCommand, detail::Vtable_NetworkGraphCommand> {
  static constexpr const ::worker::ComponentId ComponentId = 8003;
  using Data = ::improbable::graphtier::NetworkGraphCommandData;
  using GenericCommandObject = detail::GenericCommandObject_NetworkGraphCommand;

  class Update {
  public:
    // Default-constructible, copyable and movable.
    Update() = default;
    Update(Update&&) = default;
    Update(const Update&) = default;
    Update& operator=(Update&&) = default;
    Update& operator=(const Update&) = default;
    ~Update() = default;

    bool operator==(const Update&) const;
    bool operator!=(const Update&) const;

    /** Creates an Update from a ::improbable::graphtier::NetworkGraphCommandData object. */
    static Update FromInitialData(const ::improbable::graphtier::NetworkGraphCommandData& data);

    /**
     * Converts to a ::improbable::graphtier::NetworkGraphCommandData
     * object. It is an error to call this function unless *all* of the optional fields in this
     * update are filled in.
     */
    ::improbable::graphtier::NetworkGraphCommandData ToInitialData() const;

    /**
     * Replaces fields in the given ::improbable::graphtier::NetworkGraphCommandData
     * object with the corresponding fields in this update, where present.
     */
    void ApplyTo(::improbable::graphtier::NetworkGraphCommandData&) const;
  };

  /**
   * Command metaclasses for the NetworkGraphCommand component.
   * Each metaclass can be supplied as the template parameter to all command-related templated
   * types and methods in the C++ worker API.
  */
  class Commands {
  public:
    class NetworkGraph {
    public:
      static constexpr const std::uint32_t CommandId = 1;
      using ComponentMetaclass = NetworkGraphCommand;
      using Request = ::improbable::graphtier::NetworkGraphRequest;
      using Response = ::improbable::graphtier::NetworkGraphResponse;
    };
  };
};

// Implementation details.
//----------------------------------------------------------------

namespace detail {

void Serialize_NetworkGraphCommandData(
    const ::improbable::graphtier::NetworkGraphCommandData&,
    ::schema::improbable::graphtier::NetworkGraphCommandData&);

::improbable::graphtier::NetworkGraphCommandData Deserialize_NetworkGraphCommandData(
    const ::schema::improbable::graphtier::NetworkGraphCommandData&);

void Serialize_NetworkGraphRequest(
    const ::improbable::graphtier::NetworkGraphRequest&,
    ::schema::improbable::graphtier::NetworkGraphRequest&);

::improbable::graphtier::NetworkGraphRequest Deserialize_NetworkGraphRequest(
    const ::schema::improbable::graphtier::NetworkGraphRequest&);

void Serialize_NetworkGraphResponse(
    const ::improbable::graphtier::NetworkGraphResponse&,
    ::schema::improbable::graphtier::NetworkGraphResponse&);

::improbable::graphtier::NetworkGraphResponse Deserialize_NetworkGraphResponse(
    const ::schema::improbable::graphtier::NetworkGraphResponse&);

}  // ::detail
}  // ::graphtier
}  // ::improbable

#endif  // SPATIALOS_SCHEMA_improbable_graphtier_NetworkGraphCommand_schema_9461584695049045978_INCLUDED
