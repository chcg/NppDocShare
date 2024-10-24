/*
This file is part of NppDocShare Plugin for Notepad++
Copyright (C)2008 Harry <harrybharry@users.sourceforge.net>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "Socket.h" 

#define WM_SOCKET WM_USER+512

class ServerSocket {
private:
	SOCKET m_hSocket = INVALID_SOCKET;
	int m_iError = 0;
	int m_iPort = 0;
	unsigned long selectedInterface = INADDR_ANY;
public:
	ServerSocket(int iPort);
	void bindToInterface(const char * ip);
	SOCKET & getSocket();
	int getLastError() const;
	bool initiate();
	Socket * listenForClient(unsigned int timeout);
	int getPort() const;
	~ServerSocket();
	HANDLE m_hTimeoutWaitEvent = nullptr;
	unsigned int m_iTimeoutVal = 0;
};

DWORD WINAPI serverSocketTimeoutCheck(LPVOID param);

#endif //SERVERSOCKET_H
