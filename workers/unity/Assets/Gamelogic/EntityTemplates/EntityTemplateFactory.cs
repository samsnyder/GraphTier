using Assets.Gamelogic.Core;
using Improbable.Core;
using Improbable.Graphtier;
using Improbable.Math;
using Improbable.Player;
using Improbable.Unity.Core.Acls;
using Improbable.Worker;
using Quaternion = Improbable.Core.Quaternion;
using UnityEngine;
using System.Collections;
using Improbable.Collections;
using Improbable;

namespace Assets.Gamelogic.EntityTemplates
{
    public class EntityTemplateFactory : MonoBehaviour
    {
        public static SnapshotEntity CreatePlayerCreatorTemplate()
        {
            var playerCreatorEntityTemplate = new SnapshotEntity { Prefab = SimulationSettings.PlayerCreatorPrefabName };

            playerCreatorEntityTemplate.Add(new WorldTransform.Data(Coordinates.ZERO, new Quaternion(0,0,0,0)));
            playerCreatorEntityTemplate.Add(new PlayerCreation.Data());

            var acl = Acl.GenerateServerAuthoritativeAcl(playerCreatorEntityTemplate);
            playerCreatorEntityTemplate.SetAcl(acl);

            return playerCreatorEntityTemplate;
        }

        public static Entity CreatePlayerTemplate(string clientId)
        {
            var playerTemplate = new SnapshotEntity { Prefab = SimulationSettings.PlayerPrefabName };

            playerTemplate.Add(new WorldTransform.Data(Coordinates.ZERO, new Quaternion(0, 0, 0, 0)));
            playerTemplate.Add(new ClientAuthorityCheck.Data());
            playerTemplate.Add(new ClientConnection.Data(SimulationSettings.TotalHeartbeatsBeforeTimeout));

            var acl = Acl.Build()
                .SetReadAccess(CommonRequirementSets.PhysicsOrVisual)
                .SetWriteAccess<WorldTransform>(CommonRequirementSets.PhysicsOnly)
                .SetWriteAccess<ClientAuthorityCheck>(CommonRequirementSets.SpecificClientOnly(clientId))
                .SetWriteAccess<ClientConnection>(CommonRequirementSets.PhysicsOnly);
            playerTemplate.SetAcl(acl);

            return playerTemplate;
        }

//        public static SnapshotEntity CreateCubeTemplate()
//        {
//            var cubeTemplate = new SnapshotEntity { Prefab = SimulationSettings.CubePrefabName };
//
//            cubeTemplate.Add(new WorldTransform.Data(new Coordinates(0,0,5), new Quaternion(0, 0, 0, 0)));
//
//            var acl = Acl.Build()
//                .SetReadAccess(CommonRequirementSets.PhysicsOrVisual)
//                .SetWriteAccess<WorldTransform>(CommonRequirementSets.PhysicsOnly);
//            cubeTemplate.SetAcl(acl);
//
//            return cubeTemplate;
//        }

		public static SnapshotEntity CreateNetworkTemplate(List<Node> nodes, List<EntityId> sharedNetworks)
		{
			var networkTemplate = new SnapshotEntity { Prefab = "Network" };

			networkTemplate.Add(new WorldTransform.Data(new Coordinates(0,0,10), new Quaternion(0, 0, 0, 0)));
			networkTemplate.Add(new NetworkData.Data(nodes, sharedNetworks));

			var graphTierAttributeSet = Acl.MakeAttributeSet ("graphtier");
			var visualAttributeSet = Acl.MakeAttributeSet ("visual");

			var acl = Acl.Build()
				.SetReadAccess(Acl.MakeRequirementSet(graphTierAttributeSet, visualAttributeSet))
				.SetWriteAccess<WorldTransform>(Acl.MakeRequirementSet(graphTierAttributeSet))
				.SetWriteAccess<NetworkCommands>(Acl.MakeRequirementSet(graphTierAttributeSet))
				.SetWriteAccess<NetworkGraphCommand>(Acl.MakeRequirementSet(graphTierAttributeSet));
			networkTemplate.SetAcl(acl);

			return networkTemplate;
		}

		public static SnapshotEntity CreateNodeTemplate(List<EntityId> networks)
		{
			var nodeTemplate = new SnapshotEntity { Prefab = "Node" };

			nodeTemplate.Add(new WorldTransform.Data(new Coordinates(0,0,-10), new Quaternion(0, 0, 0, 0)));
			nodeTemplate.Add(new NodeCommands.Data());
					nodeTemplate.Add(new NodeData.Data(networks));

			var graphTierAttributeSet = Acl.MakeAttributeSet ("graphtier");
			var visualAttributeSet = Acl.MakeAttributeSet ("visual");

			var acl = Acl.Build()
				.SetReadAccess(Acl.MakeRequirementSet(graphTierAttributeSet, visualAttributeSet))
				.SetWriteAccess<WorldTransform>(Acl.MakeRequirementSet(graphTierAttributeSet))
				.SetWriteAccess<NodeCommands>(Acl.MakeRequirementSet(graphTierAttributeSet))
				.SetWriteAccess<NodeData>(Acl.MakeRequirementSet(graphTierAttributeSet));
			nodeTemplate.SetAcl(acl);

			return nodeTemplate;
		}
    }
}
