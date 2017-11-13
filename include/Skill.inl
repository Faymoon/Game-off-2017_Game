namespace Nz {
	inline int LuaImplReplyVal(const LuaState& state, SkillListHandle&& handle, TypeTag<SkillListHandle>)
	{
		state.PushInstance<SkillListHandle>("SkillList", handle);
		return 1;
	}
}
