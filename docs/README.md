[LeGO-LOAM Noted](https://github.com/wykxwyc/LeGO-LOAM_NOTED)

## Blog link

Some of the updates currently being made will be made on CSDN, and the content on the personal blog will be updated when all updates are completed. Content links to CSDN blogs:

1. [Map Optimization Code Understanding](https://blog.csdn.net/wykxwyc/article/details/98316127)
2. [Image reprojection code understanding](https://blog.csdn.net/wykxwyc/article/details/98317100)
3. [Feature association code understanding](https://blog.csdn.net/wykxwyc/article/details/98317544)
4. [Analysis of mathematical formulas in LeGO-LOAM code](https://blog.csdn.net/wykxwyc/article/details/98318294)
5. [LeGO-LOAM Paper Translation (Content Streamlining)](https://blog.csdn.net/wykxwyc/article/details/89605721)
6. [A question about posture transformation](https://blog.csdn.net/wykxwyc/article/details/101712524)

There are no updates on the personal blog yet:

1. [Map optimization code understanding](https://wykxwyc.github.io/2019/01/21/LeGO-LOAM-code-review-mapOptmization/)
2. [Image reprojection code understanding](https://wykxwyc.github.io/2019/01/23/LeGO-LOAM-code-review-imageProjection/)
3. [Feature association code understanding](https://wykxwyc.github.io/2019/01/24/LeGO-LOAM-code-review-featureAssociation/)
4. [Analysis of mathematical formulas in LeGO-LOAM code](https://wykxwyc.github.io/2019/08/01/The-Math-Formula-in-LeGO-LOAM/)
5. [LeGO-LOAM paper translation (content reduction).](https://wykxwyc.github.io/2019/04/26/LeGO-LOAM-Paper-Traslation-and-Summary/)

## Saving and Loading the Map

```cpp
// in the mapOptmization_createMap.cpp file
MapOptimization::~MapOptimization()
{
  dump("/tmp/dump", *isam, isamCurrentEstimate, keyframeStamps, cornerCloudKeyFrames, surfCloudKeyFrames, outlierCloudKeyFrames, cloudKeyPoses3D, cloudKeyPoses6D, gps_data);
  _input_channel.send({});
  _run_thread.join();

  _publish_global_signal.send(false);
  _publish_global_thread.join();

  _loop_closure_signal.send(false);
  _loop_closure_thread.join();
}

// in the dumpGraph.cpp file
/**
 * Function to save the graph, point clouds and gps data
 **/
void dump(const std::string& dump_directory,
  const gtsam::ISAM2& isam,
  const gtsam::Values& isam_current_estimate,
  const std::vector<double>& keyframe_stamps,
  const std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& corner_cloud_keyframes,
  const std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& surf_cloud_keyframes,
  const std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& outlier_cloud_keyframes,
  const pcl::PointCloud<pcl::PointXYZI>::Ptr& cloudKeyPoses3D,
  const pcl::PointCloud<PointTypePose>::Ptr& cloudKeyPoses6D,
  const std::vector<sensor_msgs::NavSatFix>& gps_data
)
```
