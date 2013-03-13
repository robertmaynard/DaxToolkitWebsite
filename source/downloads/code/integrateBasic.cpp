// Boost gives a bunch of warnings with nvcc if you don't specify how shared
// pointers should handle threads. Dax does not care (it is too careful about
// threading to cause hazards in shared pointers), but your code might. Thus,
// you should specify one when compiling with nvcc. If your code does not share
// shared pointers among threads, then you can just disable them as below.
// (BTW, if you forget to set this, Dax will give its own descriptive message
// with instructions on how to fix.)
#define BOOST_SP_DISABLE_THREADS

// You can specify which backend Dax will use by uncommenting one of these
// lines.  Or you can use none of these defines and let Dax pick the "best"
// backend available.
//#define DAX_DEVICE_ADAPTER DAX_DEVICE_ADAPTER_SERIAL
//#define DAX_DEVICE_ADAPTER DAX_DEVICE_ADAPTER_OPENMP
//#define DAX_DEVICE_ADAPTER DAX_DEVICE_ADAPTER_CUDA

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//Dax includes
#include <dax/cont/DeviceAdapter.h>
#include <dax/cont/Schedule.h>
#include <dax/cont/UniformGrid.h>
#include <dax/cont/worklet/Magnitude.h>

int main(int, char*[])
{
  //Define the number of points to place on each dimension of our grid.
  const dax::Id GridSize = 2;

  //Create a uniform grid upon which we will perform computations. Make it
  //2x2x2, with the origin at (0,0,0) and the farthest extent at (1,1,1).
  dax::cont::UniformGrid<> grid;
  grid.SetOrigin(dax::make_Vector3(0.0, 0.0, 0.0));
  grid.SetSpacing(dax::make_Vector3(1.0, 1.0, 1.0));
  grid.SetExtent(dax::make_Id3(0, 0, 0),
                 dax::make_Id3(GridSize-1, GridSize-1, GridSize-1));

  //Generate a scalar handle to hold the distances from the origin
  dax::cont::ArrayHandle<dax::Scalar> distancesFromOrigin;

  //Calculate the magnitude of the component.
  dax::cont::Scheduler<> scheduler;
  scheduler.Invoke(dax::worklet::Magnitude(),
                   grid.GetPointCoordinates(),
                   distancesFromOrigin);

  // Get the distances computed and print them out next to the coordinates.
  const unsigned int numPoints = grid.GetNumberOfPoints();
  vector<double> Distances(numPoints);
  distancesFromOrigin.CopyInto(Distances.begin());
  for(int pointIndex = 0; pointIndex < numPoints; pointIndex++)
    {
    dax::Vector3 Coords = grid.ComputePointCoordinates(pointIndex);
    cout << "(" << setw(3) << fixed << setprecision(1) << Coords[0] << ", "
         << setw(3) << fixed << setprecision(1) << Coords[1] << ", "
         << setw(3) << fixed << setprecision(1) << Coords[2] << ")  "
         << setprecision(5) << setw(14) << Distances[pointIndex] << endl;
    }

  return 0;
}
