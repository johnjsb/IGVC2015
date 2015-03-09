////////////////////////////////////////////////////////////////////////////////////
///
///  \file ControlDigitalVideoSensor.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Daniel Barber, Jonathan Harris
///  <br>Created: 21 March 2013
///  <br>Copyright (c) 2013
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu, jharris@ist.ucf.edu
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
#ifndef __JAUS_ENVIRONMENT_SENSING_CONTROL_DIGITAL_VIDEO_SENSOR__H
#define __JAUS_ENVIRONMENT_SENSING_CONTROL_DIGITAL_VIDEO_SENSOR__H

#include "jaus/core/Message.h"
#include "jaus/environment/EnvironmentCodes.h"
#include "jaus/environment/digitalvideo/DigitalVideoSensor.h"

namespace JAUS
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class ControlDigitalVideoSensor
    ///   \brief This class is used to report the digital Video capabilities from a sensor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_ENVIRONMENT_DLL ControlDigitalVideoSensor : public Message
    {
    public:
        ControlDigitalVideoSensor(const Address& dest = Address(), const Address& src = Address());
        ControlDigitalVideoSensor(const ControlDigitalVideoSensor& message);
        ~ControlDigitalVideoSensor() {}
        ControlDigitalVideoSensor& operator=(const ControlDigitalVideoSensor& message)
        {
            CopyHeaderData(&message);
            mSensor = message.GetSensor();
            return *this;
        }
        const DigitalVideoSensor GetSensor() const 
        {
            const DigitalVideoSensor copy = mSensor;
            return copy; 
        }
        //Add sensor
        void SetSensor(DigitalVideoSensor sensor) { mSensor = sensor; }
        // Return tue because this is a command
        virtual bool IsCommand() const { return true; }
        // Writes message payload data to the packet at the current write position.
        virtual int WriteMessageBody(Packet& packet) const;
        // Reads message payload data from the packets current read position.
        virtual int ReadMessageBody(const Packet& packet);
        // Make a copy of the message and returns pointer to it.
        virtual Message* Clone() const { return new ControlDigitalVideoSensor(*this); }
        virtual UInt GetPresenceVector() const { return 0; }
        virtual UInt GetPresenceVectorSize() const { return 0; }
        virtual UInt GetPresenceVectorMask() const { return 0; }
        // Gets the response type to the associated message, 0 if message is a response type.
        virtual UShort GetMessageCodeOfResponse() const { return CONTROL_DIGITAL_VIDEO_SENSOR_STREAM; }
        // Gets the name of the message in human readable format (for logging, etc.)
        virtual std::string GetMessageName() const { return "Control Digital Video Sensor"; }
        // Clears only message body information.
        virtual void ClearMessageBody() 
        { 
            mSensor = DigitalVideoSensor();
        }
        // Return true if payload is greater than maxPaylodSize (payload == message data only).
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize) const;
        // Prints only message body information. 
        virtual void PrintMessageBody() const;

    protected:
       DigitalVideoSensor mSensor;  ///< Sensor to control.
    };
}

#endif
/*  End of File */
