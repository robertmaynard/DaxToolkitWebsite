struct CellGradient : public dax::exec::WorkletMapCell
{
  typedef void ControlSignature(Topology, Field(Point), Field(Point), Field(Out));
  typedef _4 ExecutionSignature(_1,_2,_3);

  template<class CellTag>
  DAX_EXEC_EXPORT
  dax::Vector3 operator()(
      CellTag cellTag,
      const dax::exec::CellField<dax::Vector3,CellTag> &coords,
      const dax::exec::CellField<dax::Scalar,CellTag> &pointField) const
  {
    dax::Vector3 parametricCellCenter =
        dax::exec::ParametricCoordinates<CellTag>::Center();

    return dax::exec::CellDerivative(parametricCellCenter,
                                     coords,
                                     pointField,
                                     cellTag);
  }
};
