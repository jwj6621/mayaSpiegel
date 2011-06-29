/*
 *  mayaSpiegel.h
 *  
 *
 *  Created by jwj6621 on 6/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <map>
#include <vector>
#include <string>

#include "mayaSpiegelEngine.h"
// #include "mayaSpiegelCameraEngine.h"

using namespace std;

class mayaSpiegel {
public:
	
	bool addParticleCluster(string*, vector<double[4] >*, int);
	bool addParticleClusters(vector<string>*, vector<vector<double[4]> >*, vector<int>*, int);
	//bool addParticleClusters(vector<string>*, vector<vector<double[4]> >*, vector<int>*, vector<vector<double[4]> >*, int);
	
	
	/*
	bool addParticleCluster(string, double[][], int);
	bool addParticleClusters(string[], double[][][], int[], int);
	bool addParticleClusters(string[], double[][][], int[], double[][][], int);
	*/
	
	bool removeParticleCluster(string*);
	
	bool removeParticleClusters(vector<string>*);
	
	int getNumOfParticleClusters();
	
	//char[] getParticleClusterNames();
	
	//char[][] getParticlePositions(string);
	
	//changeParticleIncandesense(string, double[][]);
	
	bool changeParticlePositions(string*, vector<double[4]>*, int);
	
	bool changeParticlePositions(vector<string>*, vector<vector<double[4]> >*, vector<int>*, int);
private:
	
	
	map<string*, vector<double[4]>* > particleClusters;
	//map<*string, *vector<*vector<double> > particleClusterIncandesense
	
};
