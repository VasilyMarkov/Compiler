BUILD_DIR=build
if [ -d $BUILD_DIR ]; then
  echo $1
  $BUILD_DIR/Compiler $1
else
  echo "Directory build doesn't exists."
fi