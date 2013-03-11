#include <dax/CellTag.h>
#include <dax/cont/ArrayHandle.h>
#include <dax/cont/Scheduler.h>
#include <dax/cont/GenerateTopology.h>
#include <dax/cont/UniformGrid.h>
#include <dax/cont/UnstructuredGrid.h>

typedef dax::cont::GenerateTopology<dax::worklet::Tetrahedralize,
                                        dax::cont::ArrayHandleConstantValue<dax::Id>,
                                        DAX_DEFAULT_DEVICE_ADAPTER_TAG > GenerateT;
typedef typename GenerateT::ClassifyResultType  ClassifyResultType;

dax::cont::Scheduler<> scheduler;

//input grid of cubes 1,1,1 at origin 0,0,0 with extents 0,0,0 => 128,128,128
dax::cont::UniformGrid<> inputGrid;
inputGrid.SetExtent(dax::make_Id3(0), dax::make_Id3(127));

dax::cont::UnstructuredGrid<dax::CellTagTetrahedron> outputGrid;

ClassifyResultType classification(5,inputGrid.GetNumberOfCells());

GenerateT generateTets(classification,dax::worklet::Tetrahedralize() );
generateTets.SetRemoveDuplicatePoints(false);

scheduler.Invoke(generateTets,inputGrid,outputGrid);
