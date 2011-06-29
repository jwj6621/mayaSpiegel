
public class mayaSpiegelEngine {

	/*
	 * @name: addParticleCluster(s) 
	 * @description:adds one or more particle clusters to the scene
	 * @param: name:	name the names of each of the particle clusters. When passing an array, the number of names should equal to the 
	 *			number of clusters being added (or numOfClusters)
	 * @param: points: points a 2d array that holds the vector coordinates of the particles of the particle cluster. When adding only one cluster,
	 *			the outer array should equal the size of the cluster (or numOfParticles). When adding multiple clusters, points should be a 
				3d array where the outer most represents each cluster in order. The inner most array should hold a collection of 4 doubles, 
				the first three elements should be the xyz coordinates respectively, the fourth elements should equal 0.0
	 * @param: numOfParticles: number of particles that exist in the particular cluster. This should equal the number of points given. If multiple
				clusters are given, this should be an array of ints equal in size to the number of particles passed
	 * @param: numOfClusters: if multiple clusters are passed, this should equal the number of clusters
	 * @param: incandesense: should be null. Will finished this should represent the per particle colors for the given clusters
	 * @return: returns false if something went wrong, such as the number of particles given being more than the number of points that were passed
	 */
	public native boolean		addParticleCluster(char [] name, 
												   double[][] points, 
												   int numOfParticles);
	
	public native boolean		addParticleClusters(char [][] name, 
													double [][][] points, 
													int [] numOfParticles, 
													int numOfClusters);
	
	public native boolean		addParticleClusters(char [][] name, 
													double [][][] points, 
													int [] numOfParticles, 
													double [][][] incandesense, 
													int numOfClusters);
	
	/*
	 * @name: removeParticleCluster(s)
	 * @description: removes one or more particle clusters
	 * @param: name: the name or names of the particle clusters being removed
	 * @return: returns false if the given particle cluster does not exist
	 */
	public native boolean		removeParticleCluster(char [] name);
	
	public native boolean		removeParticleClusters(char [] [] name);
	
	/*
	 * @name: getNumOfParticleClusters:
	 * @description: returns the number of particle clusters that currently exist in the scene
	 * @return: the number of particle clusters that exist in the scene
	 */
	public native int			getNumOfParticleClusters( );
	
	/*
	 * @name: getParticleClusterNames();
	 * @descipition: returns the names of all of the particle clusters that exist in the scene
	 * @return: a list of names of all exisint particle clusters
	 */
	public native char [][]		getParticleClusterNames( );
	
	/*
	 * @name: getPariclePosition
	 * @description: returns a 2d double array that holds all of the xyz coordinates for the given cluster. The fourth index will always
					 hold 0
	 * @param: name: name of the particle cluster positions should be returned for
	 * @return: returns null if given cluster doesn't exist
	 */
	public native double[][]	getParticlePositions(char [] name);
	
	/*
	 * DO NOT USE
	 */
	public native boolean		changeParticleIncandesense(char [] name, 
														   double[][] incandesense);
	
	/*
	 * @name: changeParticlePositions
	 * @description: changes the positions of the paritcles for the given particle clusters
	 * @param: name: the name or names of the particle clusters being effected
	 * @param: points: the list or list of list of [x,y,z] coordinates for the particle clusters, no fourth elements of 0.0 is required
	 * @param: numOfParticles: the number of particles or list of number of particles for the given particle arrays
	 * @param: numOfCluster: the number of clusters being effected if more than one.
	 * @return: returns false if something went wrong, such as the number of particles being more than the number of points given.
	 */
	public native boolean		changeParticlePositions(char [] name, 
														double[][] points, 
														int numOfParticles);
	
	public native boolean		changeParticlePositions(char [][] name, 
														double[][][] points, 
														int[] numOfParticles, 
														int numOfClusters);
	
	
	
}