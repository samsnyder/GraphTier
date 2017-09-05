using Assets.Gamelogic.Core;
using Assets.Gamelogic.EntityTemplates;
using Improbable;
using Improbable.Worker;
using JetBrains.Annotations;
using System.IO;
using UnityEditor;
using UnityEngine;
using Improbable.Graphtier;
using Improbable.Collections;

namespace Assets.Editor 
{
	public class SnapshotMenu : MonoBehaviour
	{
		[MenuItem("Improbable/Snapshots/Generate Default Snapshot")]
		[UsedImplicitly]
		private static void GenerateDefaultSnapshot()
		{
			var snapshotEntities = new System.Collections.Generic.Dictionary<EntityId, SnapshotEntity>();
			var currentEntityId = 1;

//			snapshotEntities.Add(new EntityId(currentEntityId++), EntityTemplateFactory.CreatePlayerCreatorTemplate());

			var networkBottomAId = new EntityId(currentEntityId++);
			var networkBottomBId = new EntityId(currentEntityId++);
			var networkTopId = new EntityId(currentEntityId++);

			var nodeBottomAId = new EntityId(currentEntityId++);
			var nodeBottomBId = new EntityId(currentEntityId++);

			var exitNodeBottomAId = new EntityId(currentEntityId++);
			var exitNodeBottomBId = new EntityId(currentEntityId++);

			snapshotEntities.Add(networkBottomAId, EntityTemplateFactory.CreateNetworkTemplate(
				new List<Node>(new Node[] {
					new Node(nodeBottomAId,
						new List<Edge>(new Edge[]{new Edge(exitNodeBottomAId, 10)})
					),
					new Node(nodeBottomAId,
						new List<Edge>(new Edge[]{new Edge(nodeBottomAId, 20)})
					)
				}),
				new List<EntityId>(new EntityId[] {networkTopId, networkBottomAId})
			));

//			snapshotEntities.Add(networkBottomBId, EntityTemplateFactory.CreateNetworkTemplate(
//				new List<EntityId>(new EntityId[] {nodeBottomBId, exitNodeBottomBId}),
//				new List<EntityId>(new EntityId[] {networkTopId})
//			));
//
//			snapshotEntities.Add(networkTopId, EntityTemplateFactory.CreateNetworkTemplate(
//				new List<EntityId>(new EntityId[] {exitNodeBottomAId, exitNodeBottomBId}),
//				new List<EntityId>()
//			));

//
//			snapshotEntities.Add(nodeBottomAId, EntityTemplateFactory.CreateNodeTemplate(
//				new List<NetworkAttachment>(new NetworkAttachment[] {
//					new NetworkAttachment(new Option<EntityId>(networkBottomAId))
//				})
//			));
//
//			snapshotEntities.Add(nodeBottomBId, EntityTemplateFactory.CreateNodeTemplate(
//				new List<NetworkAttachment>(new NetworkAttachment[] {
//					new NetworkAttachment(new Option<EntityId>(networkBottomBId))
//				})
//			));
//
//			snapshotEntities.Add(exitNodeBottomAId, EntityTemplateFactory.CreateNodeTemplate(
//				new List<NetworkAttachment>(new NetworkAttachment[] {
//					new NetworkAttachment(new Option<EntityId>(networkBottomAId)),
//					new NetworkAttachment(new Option<EntityId>(networkTopId))
//				})
//			));
//
//			snapshotEntities.Add(exitNodeBottomBId, EntityTemplateFactory.CreateNodeTemplate(
//				new List<NetworkAttachment>(new NetworkAttachment[] {
//					new NetworkAttachment(new Option<EntityId>(networkBottomBId)),
//					new NetworkAttachment(new Option<EntityId>(networkTopId))
//				})
//			));

			SaveSnapshot(snapshotEntities);
		}

		private static void SaveSnapshot(System.Collections.Generic.IDictionary<EntityId, SnapshotEntity> snapshotEntities)
		{
			File.Delete(SimulationSettings.DefaultSnapshotPath);
			var maybeError = Snapshot.Save(SimulationSettings.DefaultSnapshotPath, snapshotEntities);

			if (maybeError.HasValue)
			{
				Debug.LogErrorFormat("Failed to generate initial world snapshot: {0}", maybeError.Value);
			}
			else
			{
				Debug.LogFormat("Successfully generated initial world snapshot at {0}", SimulationSettings.DefaultSnapshotPath);
			}
		}
	}
}
