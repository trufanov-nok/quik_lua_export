require("quik_lua_export")

function OnAllTrade(alltrades)
    return quik_lua_export.OnAllTrade(alltrades)
end

function main()
	while not stopped do
		sleep(500)                
                end
end