/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PrecondViolatedExcep.h
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on April 22, 2019, 4:33 PM
 */

#ifndef PRECONDVIOLATEDEXCEP_H
#define PRECONDVIOLATEDEXCEP_H

#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error {
public:
    PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep

#endif /* PRECONDVIOLATEDEXCEP_H */

