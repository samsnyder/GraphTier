using Assets.Gamelogic.Core;
using Improbable.Core;
using Improbable.Graphtier;
using Improbable.Player;
using Improbable.Unity.Core.Acls;
using Improbable.Worker;
using UnityEngine;
using System.Collections;
using Improbable.Collections;
using Improbable;
using Improbable.Unity.Entity;

namespace Assets.Gamelogic.EntityTemplates
{
    public class EntityTemplateFactory : MonoBehaviour
    {
        public static Entity CreatePlayerCreatorTemplate()
        {
			var template = EntityBuilder.Begin()
		           .AddPositionComponent(Coordinates.ZERO.ToUnityVector(), CommonRequirementSets.PhysicsOnly)
		           .AddMetadataComponent(SimulationSettings.PlayerCreatorPrefabName)
		           .SetPersistence(true)
		           .SetReadAcl(CommonRequirementSets.PhysicsOrVisual)
                   .AddComponent(new PlayerCreation.Data(), CommonRequirementSets.PhysicsOnly)
		           .Build();
			return template;
        }

        public static Entity CreatePlayerTemplate(string clientId)
        {
            var template =
                EntityBuilder.Begin()
                             .AddPositionComponent(Coordinates.ZERO.ToUnityVector(),
                                                   CommonRequirementSets.PhysicsOnly)
                             .AddMetadataComponent(SimulationSettings.PlayerPrefabName)
                             .SetPersistence(false)
                             .SetReadAcl(CommonRequirementSets.PhysicsOrVisual)
                             .AddComponent(new ClientAuthorityCheck.Data(),
                                           CommonRequirementSets.SpecificClientOnly(clientId))
                             .AddComponent(new ClientConnection.Data(SimulationSettings.TotalHeartbeatsBeforeTimeout),
                                           CommonRequirementSets.PhysicsOnly)
                             .Build();
            return template;
        }

		public static Entity CreateNetworkTemplate(List<Node> nodes, List<EntityId> sharedNetworks)
		{
			var graphTierAttributeSet = Acl.MakeAttributeSet("graphtier");
			var visualAttributeSet = Acl.MakeAttributeSet("visual");

            var template =
                EntityBuilder.Begin()
                             .AddPositionComponent(new Coordinates(0, 0, 10).ToUnityVector(),
                                                   Acl.MakeRequirementSet(graphTierAttributeSet))
                             .AddMetadataComponent("Network")
                             .SetPersistence(true)
                             .SetReadAcl(Acl.MakeRequirementSet(graphTierAttributeSet, visualAttributeSet))
                             .AddComponent(new NetworkData.Data(nodes, sharedNetworks),
                                           Acl.MakeRequirementSet(graphTierAttributeSet))
                             .AddComponent(new NetworkCommands.Data(), Acl.MakeRequirementSet(graphTierAttributeSet))
                             .Build();

            return template;
		}

		public static Entity CreateNodeTemplate(List<EntityId> networks)
		{
			var graphTierAttributeSet = Acl.MakeAttributeSet("graphtier");
			var visualAttributeSet = Acl.MakeAttributeSet("visual");

            var template =
                EntityBuilder.Begin()
                             .AddPositionComponent(new Coordinates(0, 0, -10).ToUnityVector(),
                                                  Acl.MakeRequirementSet(graphTierAttributeSet))
                             .AddMetadataComponent("Node")
                             .SetPersistence(true)
                             .SetReadAcl(Acl.MakeRequirementSet(graphTierAttributeSet, visualAttributeSet))
                             .AddComponent(new NodeCommands.Data(), Acl.MakeRequirementSet(graphTierAttributeSet))
                             .AddComponent(new NodeData.Data(networks), Acl.MakeRequirementSet(graphTierAttributeSet))
                             .Build();

            return template;
		}
    }
}
