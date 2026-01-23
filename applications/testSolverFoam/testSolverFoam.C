/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author(s)
     \\/     M anipulation  |
-------------------------------------------------------------------------------
            testSolverFoam | Copyright (C) 2026 Daniil Panov
-------------------------------------------------------------------------------
License
    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    testSolverFoam

Description
    Test solver for developer container repository.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H" // Comment this if using ORG version!
// #include "argList.H" // Uncomment this if using COM version!

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //ф

int main(int argc, char *argv[])
{
    Foam::Info<< "\nHello world\n" << Foam::endl;
    return 0;
}

