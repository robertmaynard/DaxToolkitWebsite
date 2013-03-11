
#include <dax/cont/ArrayHandle.h>
#include <dax/cont/Scheduler.h>
#include <dax/cont/UniformGrid.h>


//construct a handle to store the results

  dax::cont::ArrayHandle<dax::Scalar> magnitudeHandle;

//input grid of cubes 1,1,1 at origin 0,0,0 with extents 0,0,0 => 128,128,128
dax::cont::UniformGrid<> inputGrid;
inputGrid.SetExtent(dax::make_Id3(0), dax::make_Id3(127));

//construct a scheduler and launch the magnitude worklet.
dax::cont::Scheduler<> scheduler;
scheduler.Invoke(dax::worklet::Magnitude(),
                 grid->GetPointCoordinates(),
                 magnitudeHandle);
