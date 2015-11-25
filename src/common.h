#pragma once

#include "data/entity.h"
#include "render/render.h"
#include "physics.h"
#include <btBulletDynamicsCommon.h>

class btTriangleIndexVertexArray;
class btBvhTriangleMeshShape;
class btCollisionShape;

namespace VI
{

struct Empty : public Entity
{
	Empty();
};

struct Prop : public Entity
{
	Prop(const AssetID, const AssetID = AssetNull, const AssetID = AssetNull);
};

struct StaticGeom : public Entity
{
	StaticGeom(AssetID, const Vec3&, const Quat&, short = btBroadphaseProxy::StaticFilter, short = ~btBroadphaseProxy::StaticFilter);
};

struct PhysicsEntity : public Entity
{
	PhysicsEntity(AssetID, const Vec3&, const Quat&, RigidBody::Type, const Vec3&, float, short, short);
};

struct Noclip : public Entity
{
	Noclip();
};

struct NoclipControl : public ComponentType<NoclipControl>
{
	float angle_horizontal;
	float angle_vertical;

	Camera* camera;

	NoclipControl();
	~NoclipControl();

	void update(const Update&);
	void awake();
};

}
