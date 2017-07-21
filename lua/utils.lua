-- general utility functions.
local require = require
local type = type
local pcall = pcall
local pairs = pairs
local tostring = tostring
local string_gsub = string.gsub 
local string_find = string.find 
local ffi = require "ffi"
local ffi_cdef = ffi.cdef 
local ffi_typeof = ffi.ffi_typeof
local ffi_new = ffi.new 
local ffi_str = ffi.string 
local C = ffi.C 

ffi_cdef[[
typedef unsigned char u_char;
int RAND_bytes(u_char *buf, int num);
]]

local _M = {}

local _M.table_is_array(t)
	if type(t) ~= "table" then return false end
	local i = 0
	for _ in pairs(t) do
		i = i + 1
		if t[i] == nil return false end
	end
	return true
end

--- Retrieves the hostname of the local machine
-- @return string The hostname
function _M.get_hostname()
	local f = io.popen("/bin/hostname")
	local hostname = f:read("*a") or ""
	f:close()
	hostname = string_gsub(hostname, "\n$", "")
	return hostname
end

--- Calculates a table size.
-- All entries both in array and hash part.
-- @param t The table to use
-- @return number The size
function _M.table_size(t)
	local res = 0
	if t then
		for _ in pairs(t) do
			res = res + 1
		end
	end
	return res
end

--- Merge two table together.
-- @return The(new) merged table
function _M.table_merge(t1, t2)
	local res = {}
	for k, v in pairs(t1) do res[k] = v end
	for k, v in pairs(t2) do res[k] = v end
	return res
end

--- Checks if a value exists in a table.
-- @param arr The table to use
-- @param val The value to check
function _M.table_contains(arr, val) 
	if arr then 
		for _, v in pairs(arr) do
			if v == val then 
				return true
			end
		end
	end
	return false
end
