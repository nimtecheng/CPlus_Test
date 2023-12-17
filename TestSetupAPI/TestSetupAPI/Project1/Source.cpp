#include<Windows.h>
#include<SetupAPI.h>
#include<iostream>
#include<string>
#pragma comment(lib, "setupapi.lib")

bool IsDeviceinList(const char* deviceName)
{
	bool findDevice = false;
	int nameLength = strlen(deviceName);
	HDEVINFO hdevinfo = SetupDiGetClassDevs(NULL,
		NULL, NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES);
	if (hdevinfo != INVALID_HANDLE_VALUE)
	{
		DWORD MemberIndex = 0;
		SP_DEVINFO_DATA sp_devinfo_data;
		ZeroMemory(&sp_devinfo_data, sizeof(sp_devinfo_data));
		sp_devinfo_data.cbSize = sizeof(sp_devinfo_data);
		while (SetupDiEnumDeviceInfo(hdevinfo, MemberIndex, &sp_devinfo_data) && (!findDevice))
		{
			//DWORD PropertyRegDataType;
			//DWORD RequiredSize;
			TCHAR PropertyBuffer[100];
			if (SetupDiGetDeviceRegistryProperty(hdevinfo,
				&sp_devinfo_data,
				SPDRP_DEVICEDESC,
				NULL,
				(PBYTE)&PropertyBuffer,
				sizeof(PropertyBuffer),
				NULL) && (!findDevice))
			{
				int PropertyBufferSize = 0;
				for (int i = 0; PropertyBuffer[i++] != '\0'; PropertyBufferSize++);
				if (nameLength <= PropertyBufferSize)
				{
					//double loop to search the given string in list or not
					for (int i = 0; i <= (PropertyBufferSize - nameLength); i++)
					{
						int match = 0;
						for (int j = 0; j < nameLength; j++)
						{
							if ((char)PropertyBuffer[i + j] == deviceName[j])
								match++;
							else
								break;
						}
						if (match == nameLength)
						{
							findDevice = true;
							break;
						}
					}
				}
			}
			MemberIndex++;
		}
	}
	SetupDiDestroyDeviceInfoList(hdevinfo);
	return findDevice;

}

void outputDeviceInfo()
{
	//The SetupDiGetClassDevs function returns a handle to a device information set 
	//that contains requested device information elements for a local computer.
	HDEVINFO hdevinfo = SetupDiGetClassDevs(NULL,
		NULL, NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES);
	if (hdevinfo != INVALID_HANDLE_VALUE)
	{
		DWORD MemberIndex = 0;
		SP_DEVINFO_DATA sp_devinfo_data;
		ZeroMemory(&sp_devinfo_data, sizeof(sp_devinfo_data));
		sp_devinfo_data.cbSize = sizeof(sp_devinfo_data);

		//The SetupDiEnumDeviceInfo function returns a SP_DEVINFO_DATA structure 
		//that specifies a device information element in a device information set.
		while (SetupDiEnumDeviceInfo(hdevinfo, MemberIndex, &sp_devinfo_data))
		{
			TCHAR PropertyBuffer[100];
			//The SetupDiGetDeviceRegistryProperty function retrieves
			//a specified Plug and Play device property.
			if (SetupDiGetDeviceRegistryProperty(hdevinfo,
				&sp_devinfo_data,
				SPDRP_DEVICEDESC,
				NULL,
				(PBYTE)&PropertyBuffer,
				sizeof(PropertyBuffer),
				NULL))
			{					
					std::wcout << MemberIndex << ":"<< (wchar_t*)PropertyBuffer<<std::endl;
			}
			MemberIndex++;

		}


	}

}

int main()
{
	//set chinese character
	std::locale::global(std::locale(""));

	//
	HDEVINFO hdevinfo = SetupDiGetClassDevs(NULL,
		NULL, NULL, DIGCF_ALLCLASSES| DIGCF_PRESENT);

	if (hdevinfo != INVALID_HANDLE_VALUE)
	{
		DWORD MemberIndex = 0;
		SP_DEVINFO_DATA sp_devinfo_data;
		ZeroMemory(&sp_devinfo_data, sizeof(sp_devinfo_data));
		sp_devinfo_data.cbSize = sizeof(sp_devinfo_data);
		while (SetupDiEnumDeviceInfo(hdevinfo, MemberIndex, &sp_devinfo_data))
		{
			TCHAR PropertyBuffer[100];
			if (SetupDiGetDeviceRegistryProperty(hdevinfo,
				&sp_devinfo_data,
				SPDRP_DEVICEDESC,
				NULL,
				(PBYTE)&PropertyBuffer,
				sizeof(PropertyBuffer),
				NULL))
			{

				std::wcout << MemberIndex << ":" << (wchar_t*)PropertyBuffer << std::endl;

			}
			MemberIndex++;

		}

	}
	return 0;
}