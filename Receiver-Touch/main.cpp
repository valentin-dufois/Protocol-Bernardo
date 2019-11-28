//
//  main.cpp
//  pb-receiver-touch
//
//  Created by Valentin Dufois on 2019-11-19.
//

/* Shared Use License: This file is owned by Derivative Inc. (Derivative) and
 * can only be used, and/or modified for use, in conjunction with
 * Derivative's TouchDesigner software, and only if you are a licensee who has
 * accepted Derivative's TouchDesigner license or assignment agreement (which
 * also govern the use of this file).  You may share a modified version of this
 * file with another authorized licensee of Derivative's TouchDesigner software.
 * Otherwise, no redistribution or sharing of this file, with or without
 * modification, is permitted.
 */

#include "Core.hpp"

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <assert.h>

// These functions are basic C function, which the DLL loader can find
// much easier than finding a C++ Class.
// The DLLEXPORT prefix is needed so the compile exports these functions from the .dll
// you are creating
extern "C" {

	DLLEXPORT
	void
	FillCHOPPluginInfo(CHOP_PluginInfo *info)
	{
		// Always set this to CHOPCPlusPlusAPIVersion.
		info->apiVersion = CHOPCPlusPlusAPIVersion;

		info->customOPInfo.majorVersion = 0;
		info->customOPInfo.minorVersion = 1;

		// The opType is the unique name for this CHOP. It must start with a
		// capital A-Z character, and all the following characters must lower case
		// or numbers (a-z, 0-9)
		info->customOPInfo.opType->setString("Pbreceiver");

		// The opLabel is the text that will show up in the OP Create Dialog
		info->customOPInfo.opLabel->setString("PB-Receiver");
		info->customOPInfo.opIcon->setString("PBR");

		// Information about the author of this OP
		info->customOPInfo.authorName->setString("Valentin Dufois");
		info->customOPInfo.authorEmail->setString("valentin@dufois.fr");

		// It does not accept any inputs
		info->customOPInfo.maxInputs = 0;
	}

	DLLEXPORT
	Core *
	CreateCHOPInstance(const OP_NodeInfo * info)
	{
		// Return a new instance of your class every time this is called.
		// It will be called once per CHOP that is using the .dll
		return new Core();
	}

	DLLEXPORT
	void
	DestroyCHOPInstance(Core * instance)
	{
		// Delete the instance here, this will be called when
		// Touch is shutting down, when the CHOP using that instance is deleted, or
		// if the CHOP loads a different DLL	
		delete (Core *)instance;
	}

};
