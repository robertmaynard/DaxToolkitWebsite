class Magnitude : public dax::exec::WorkletMapField
{
public:
  typedef void ControlSignature(Field(In), Field(Out));
  typedef void ExecutionSignature(_1,_2);

  DAX_EXEC_EXPORT void operator()(const dax::Vector3 &inValue,
                                  dax::Scalar &outValue) const
    { outValue = dax::math::Magnitude(inValue); }
};
