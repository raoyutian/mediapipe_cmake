@echo on 
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat
cd ~%dp0
mkdir build_win
cd build_win
cmake .. -GNinja  -DCMAKE_POLICY_VERSION_MINIMUM=3.5  -DCMAKE_BUILD_TYPE=Release -DOpenCV_DIR="../opencv_lite\build"
ninja -j8
@pause
