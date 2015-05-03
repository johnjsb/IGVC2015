////////////////////////////////////////////////////////////////////////////////////
///
///  \file TCPClient.h
///  \brief This file contains software for creating a TCP client connection.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 22 June 2007
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu
///  <br>Web:  http://active.ist.ucf.edu
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///      * Redistributions of source code must retain the above copyright
///        notice, this list of conditions and the following disclaimer.
///      * Redistributions in binary form must reproduce the above copyright
///        notice, this list of conditions and the following disclaimer in the
///        documentation and/or other materials provided with the distribution.
///      * Neither the name of the ACTIVE LAB, IST, UCF, nor the
///        names of its contributors may be used to endorse or promote products
///        derived from this software without specific prior written permission.
/// 
///  THIS SOFTWARE IS PROVIDED BY THE ACTIVE LAB''AS IS'' AND ANY
///  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL UCF BE LIABLE FOR ANY
///  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
///  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
///  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
///  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
///  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
////////////////////////////////////////////////////////////////////////////////////
#ifndef __CXUTILS_TCP_CLIENT_SOCKET_H
#define __CXUTILS_TCP_CLIENT_SOCKET_H

#include "cxutils/networking/Socket.h"

namespace CxUtils
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class TcpClient
    ///   \brief Socket which connects over TCP to a server. 
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class CX_UTILS_DLL TcpClient : public Socket
    {
    public:
        TcpClient();
        virtual ~TcpClient();
        int InitializeSocket(const IP4Address& ipAddress,
                             const unsigned short port,
                             const int stimeout = 0,
                             const int rtimeout = 0);
        virtual void Shutdown();
        inline virtual IP4Address GetDestinationAddress() const { return mServerAddress; }
        inline virtual IP4Address GetSourceAddress() const { return mSourceID; }
        IP4Address GetServerAddress() const { return mServerAddress; }
        inline int GetPort() const { return mPort; }
    private:
        virtual int SendFromBuffer(const char* buffer, 
                                   const unsigned int length) const;
        virtual int RecvToBuffer(char* buffer, 
                                 const unsigned int length, 
                                 const long int timeOutMilliseconds = 0, 
                                 IPAddress* ipAddress = NULL,
                                 unsigned short* port = NULL) const;
        int mPort;                  ///<  Port used for TCP/IP.
        long mComputer;             ///<  Computer ID.
        IP4Address mServerAddress;  ///<  IP address of server we are connected to.
        IP4Address mSourceID;       ///<  Source IP Address.
    };
}

#endif
/*  End of File */
