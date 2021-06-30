from conans import ConanFile
import glob
import os
import shutil

class GuiConan(ConanFile):
    name = "fpocketLibs"
    settings = "os", "compiler", "build_type", "arch"
    requires = ("VMD/1.9.3@cresset/stable")
    generators = "cmake_paths"

    def imports(self):
        vmd = self.deps_cpp_info["VMD"]

        os.makedirs(os.getcwd() + "/bin", exist_ok=True)

        files = []
        for item in (*vmd.lib_paths, *vmd.bin_paths):
            if self.settings.get_safe("os") == "Windows":
                files.extend(glob.glob(item + "/*.dll"))
                files.extend(glob.glob(item + "/*.pdb"))
            elif self.settings.get_safe("os") == "Linux":
                files.extend(glob.glob(item + "/*.so*"))
            elif self.settings.get_safe("os") == "Macos":
                files.extend(glob.glob(item + "/*.dylib"))
        for file in files:
            dest = os.getcwd() + "/bin/" + os.path.basename(file)
            if not os.path.isfile(dest):
                print(f"Copy {file} -> {dest}")
                shutil.copyfile(file, dest, follow_symlinks=False)
