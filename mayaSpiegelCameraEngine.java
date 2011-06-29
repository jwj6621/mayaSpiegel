public class mayaSpiegelCameraEngine {


	static
	{
		System.loadLibrary("mayaSpiegel");
	}
	
	
	/*
	 * @name: addCamera
	 * @description: adds a camera of the given name at the given point with the given target and the given up
	 */
	public native boolean addCamera(String name);
	public native boolean addCamera(String name, double[] point);
	public native boolean addCamera(String name, double[] point, double[] target);
	public native boolean addCamera(String name, double[] point, double[] up);
	public native boolean addCamera(String name, double[] point, double[] target, double[] up);
	
	/*
	 * @name: editCamera
	 * @description: edits the given camera with a new point position, target, and/or up
	 */
	public native boolean editCamera(String name, double[] point);
	public native boolean editCamera(String name, double[] point, double[] target);
	public native boolean editCamera(String name, double[] point, double[] up);
	public native boolean editCamera(String name, double[] point, double[] target, double[] up);
	
	/*
	 * @name: removeCamera
	 * @description: remove the given camera
	 */
	public native boolean removeCamera(String name);
	
	/*
	 * @name: getCameraNames
	 * @description: get a list of all the camera names
	 */
	public native String[] getCameraNames();
	
	/*
	 * @name: getCameraPosition
	 */
	public native double[] getCameraPosition(String name);
	
	/*
	 * @name: getCameraTargetPosition
	 */
	public native double[] getCameraTargetPosition(String name);
	
	/*
	 * @name: getCameraUpTarget
	 */
	public native double[] getCameraUpTarget(String name);
	
	/*
	 * @name: takeImage
	 * @param: the name of the camera to take the image
	 * @return: returns the name of the path of the outputed image file
	 */
	public native String takeImage(String name);
	
	/*
	 * DO NOT USE
	 */
	public native String makeSteroscopic(String name1, String name2);
	
	
	
}