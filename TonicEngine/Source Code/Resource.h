#ifndef __Resource_H__
#define __Resource_H__

#include "Globals.h"
#include "Application.h"


enum class RESOURCE_TYPE
{
	NONE = -1,
	MESH,
	TEXTURE,
	MODEL
};

class Resource
{

public:
	Resource(uint UUID, RESOURCE_TYPE type);
	virtual ~Resource();
	RESOURCE_TYPE GetType() const;

	bool IsLoadedToMemory() const;
	bool LoadToMemory();

	uint GetUUID() const;
	const char* GetFile() const;
	const char* GetImportedFile() const;
	void UpdateNumRef();


	virtual void Load(const nlohmann::json& config);
	virtual void Save(nlohmann::json& config) const;

	virtual bool LoadInMemory() = 0;
	virtual void ReleaseMemory() = 0;
public:
	uint res_UUID = 0;
	std::string file;
	std::string imported_file;
	RESOURCE_TYPE type = RESOURCE_TYPE::NONE;
	uint loaded = 0;
};

#endif
