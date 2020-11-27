
local ROLE_SUB_MODULE = {
   roleGM                    = "require role.gm.RoleGM",
   roleBagObj                = "require role.bag.RoleBag",
  
}
for module_name, module_class in pairs(ROLE_SUB_MODULE) do
        -- self[module_name] = module_class.new()
        print(module_name,module_class)
    end