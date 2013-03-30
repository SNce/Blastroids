
template <typename DriverType>
s32 CRenderer<DriverType>::Initialize(void* params)
{
	m_pDriver = new DriverType();

	m_pDriver->CreateDriverContext(params);
	return 0;
}

template <typename DriverType>
void CRenderer<DriverType>::ReshapeWindow(u32 width, u32 height)
{

}

