namespace dax     {
namespace worklet {
namespace detail  {
DAX_EXEC_CONSTANT_EXPORT const unsigned char PossibleTetraSplitCases[10][4] =
  {
  {1,3,6,2}, {0,1,3,4}, {1,4,5,6}, {3,6,7,4}, {1,4,6,3},
  {2,1,5,0}, {0,2,3,7}, {2,5,6,7}, {0,7,4,5}, {0,2,7,5}
  };
}

//currently only supports voxel to tet's
class Tetrahedralize : public dax::exec::WorkletGenerateTopology
{
public:
  typedef void ControlSignature(Topology, Topology(Out));
  typedef void ExecutionSignature(Vertices(_1),Vertices(_2), WorkId, VisitIndex);

  DAX_EXEC_EXPORT
  void operator()(const dax::exec::CellVertices<dax::CellTagVoxel> &inVertices,
                  dax::exec::CellVertices<dax::CellTagTetrahedron> &outVertices,
                  const dax::Id inputCellId,
                  const dax::Id visitIndex) const
  {
  //instead of switching on id % 2, we take it as zero or one and multiple
  //by 5 to get the correct index in our lookup table
  dax::Id lookupTablePos = visitIndex + (  5 * inputCellId % 2 );

  outVertices[0] = inVertices[ detail::PossibleTetraSplitCases[lookupTablePos][0] ];
  outVertices[1] = inVertices[ detail::PossibleTetraSplitCases[lookupTablePos][1] ];
  outVertices[2] = inVertices[ detail::PossibleTetraSplitCases[lookupTablePos][2] ];
  outVertices[3] = inVertices[ detail::PossibleTetraSplitCases[lookupTablePos][3] ];
  outVertices[4] = inVertices[ detail::PossibleTetraSplitCases[lookupTablePos][4] ];
  }
};
} }
