local socket = require("socket")

print('listening')
s = socket.bind("*", 9999)
s:settimeout(1)

while true do 
    print('accepting connection')
    local c = s:accept()
    if c then
        c:settimeout(1)
        local rec = c:receive()
        print('received ' .. rec)
        c:close()
        if rec == "quit" then break end
        if rec == "exec" then 
            print("running ping in background")
            os.execute('sleep 10s &')
            break
        end
    end
end

print('closing server')
s:close()
