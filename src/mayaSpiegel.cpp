/*
 *  mayaSpiegel.cpp
 *  
 *
 *  Created by jwj6621 on 6/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "mayaSpiegel.h"
//#include "mayaSpiegelCameraEngine.h"


bool mayaSpiegel::addParticleCluster(string *name, vector<double[4] > *points, int numOfParticles)
{
  
  pair<map<string*, vector<double[4]>* >::iterator,bool> ret;
  //particleClusters.insert(pair<string*, vector<double[4]*> > (&name, &points));
  ret = particleClusters.insert( pair<string*, vector<double[4]>* >(name, points));
  return(ret.second);

}


bool mayaSpiegel::addParticleClusters(vector<string>*, vector<vector<double[4]> >*, vector<int>*, int)
{
  
}
/*
 * Class:     mayaSpiegelEngine
 * Method:    addParticleCluster
 * Signature: ([C[[DI)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_addParticleCluster
(JNIEnv * env, jobject, jcharArray jname, jobjectArray jpoints, jint jnumOfParticles)
{
  //string newName = (string) name;
	
  char * name = (char*)jname;
  int		numOfParticles = (int)jnumOfParticles;
  double localDoubleArray[jnumOfParticles][4];
	
  for (int i = 0; i < jnumOfParticles; i++)
    {
      jdoubleArray oneDim = (jdoubleArray)env->GetObjectArrayElement(jpoints, i);
      jdouble *element = env->GetDoubleArrayElements(oneDim, 0);
      for (int j = 0; j < 4; j++) {
        localDoubleArray[i][j] = element[j];
      }
    }
	
	
	
	
	
}

/*
 * Class:     mayaSpiegelEngine
 * Method:    addParticleClusters
 * Signature: ([[C[[[D[II)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_addParticleClusters___3_3C_3_3_3D_3II
(JNIEnv *, jobject, jobjectArray, jobjectArray, jintArray, jint);

/*
 * Class:     mayaSpiegelEngine
 * Method:    addParticleClusters
 * Signature: ([[C[[[D[I[[[DI)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_addParticleClusters___3_3C_3_3_3D_3I_3_3_3DI
(JNIEnv *, jobject, jobjectArray, jobjectArray, jintArray, jobjectArray, jint);

/*
 * Class:     mayaSpiegelEngine
 * Method:    removeParticleCluster
 * Signature: ([C)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_removeParticleCluster
(JNIEnv *, jobject, jcharArray);

/*
 * Class:     mayaSpiegelEngine
 * Method:    removeParticleClusters
 * Signature: ([[C)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_removeParticleClusters
(JNIEnv *, jobject, jobjectArray);

/*
 * Class:     mayaSpiegelEngine
 * Method:    getNumOfParticleClusters
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_mayaSpiegelEngine_getNumOfParticleClusters
(JNIEnv *, jobject);

/*
 * Class:     mayaSpiegelEngine
 * Method:    getParticleClusterNames
 * Signature: ()[[C
 */
JNIEXPORT jobjectArray JNICALL Java_mayaSpiegelEngine_getParticleClusterNames
(JNIEnv *, jobject);

/*
 * Class:     mayaSpiegelEngine
 * Method:    getParticlePositions
 * Signature: ([C)[[D
 */
JNIEXPORT jobjectArray JNICALL Java_mayaSpiegelEngine_getParticlePositions
(JNIEnv *, jobject, jcharArray);

/*
 * Class:     mayaSpiegelEngine
 * Method:    changeParticleIncandesense
 * Signature: ([C[[D)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_changeParticleIncandesense
(JNIEnv *, jobject, jcharArray, jobjectArray);

/*
 * Class:     mayaSpiegelEngine
 * Method:    changeParticlePositions
 * Signature: ([C[[DI)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_changeParticlePositions___3C_3_3DI
(JNIEnv *, jobject, jcharArray, jobjectArray, jint);

/*
 * Class:     mayaSpiegelEngine
 * Method:    changeParticlePositions
 * Signature: ([[C[[[D[II)Z
 */
JNIEXPORT jboolean JNICALL Java_mayaSpiegelEngine_changeParticlePositions___3_3C_3_3_3D_3II
(JNIEnv *, jobject, jobjectArray, jobjectArray, jintArray, jint);
