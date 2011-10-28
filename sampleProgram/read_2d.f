c---------< Sample program by fortran > -------------------------------
c         Sample program by fortran to read 2D data along horizontal section
c----------------------------------------------------------------------
          parameter  (imt = 3600, jmt = 1500 )
          dimension  da(imt, jmt) 
    c 
          open ( 10, file = 'eta_5012.dta', form='unformatted' ,
     #           access='direct', recl=imt*jmt*4) 
    c 
          read ( 10, rec=1 ) da

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
<grid information>

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   for Sea Surface Height, Heat Flux, Salinity Flux, 
       Salinity, and Potemtial Temperature
        imt  :  Zonal direction        1(0.05E)    ------->  3600(359.95E) 
        jmt  :  Meridional direction   1(74.95S)  ------->   1500(74.95N)      

   for Wind stress and Velocity
        imt  :  Zonal direction        1(0.1E)    ------->  3600(360.0E) 
        jmt  :  Meridional direction   1(74.9S)  ------->   1500(75.0N)      


        Unit :  Sea Surface Height	cm
		Surface Heat Flux	cal/cm^2/sec
		Surface Salinity Flux	g/cm^2/sec
		Wind Stress		dyne/cm^2

		Salinity      		psu = model*1000+35
                Potential Temperature   degree
                Velocity		cm/sec

        Value of -1.0 E+34 is filled for land region. 
