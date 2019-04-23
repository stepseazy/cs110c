/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PrecondViolatedExcep.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on April 22, 2019, 4:33 PM
 */

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message) :
logic_error("Precondition Violated Exception: " + message) {
} // end constructor

