// Copyright (C) 2017-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2023 Astra
// Copyright (C) 2023 AlgoRND
//
// License: GPL
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Contacting ICE: <https://www.theice.com/contact>
// Target: atf_ci (exe) -- Normalization tests (see citest table)
// Exceptions: yes
// Header: include/atf_ci.h
//

#include "include/algo.h"
#include "include/gen/atf_ci_gen.h"
#include "include/gen/atf_ci_gen.inl.h"

#include "include/lib_ctype.h"

namespace atf_ci { // update-hdr
    // Dear human:
    //     Text from here to the closing curly brace was produced by scanning
    //     source files. Editing this text is futile.
    //     To refresh the contents of this section, run 'update-hdr'.
    //     To convert this section to a hand-written section, remove the word 'update-hdr' from namespace line.

    // -------------------------------------------------------------------
    // cpp/atf/ci/acr_ed.cpp
    //

    // Runs in sandbox
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_acr_ed_ssimdb();

    // Runs in sandbox
    // void citest_acr_ed_ssimfile();

    // Runs in sandbox
    // void citest_acr_ed_target();

    // -------------------------------------------------------------------
    // cpp/atf/ci/bootstrap.cpp
    //

    // Create a bootstrap file for each build dir
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_bootstrap();

    // -------------------------------------------------------------------
    // cpp/atf/ci/cppcheck.cpp
    //

    // Run static code analyzer
    // Check Linux only
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_cppcheck();

    // -------------------------------------------------------------------
    // cpp/atf/ci/main.cpp
    //

    // Check that a list of directories specified with DIRS is clean
    // Nothing is done if an error exit code is already set, since
    // this error might have been caused by the previous error.
    // Return TRUE if test succeeds
    bool CheckCleanDirs(strptr dirs);

    // Check that DIR is not generated by the test
    void CheckNoDir(strptr dir);
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_atf_amc();
    // void citest_atf_unit();
    // void citest_atf_comp();
    // void citest_atf_comp_cov();
    // void citest_atf_comp_mem();
    // void citest_normalize_amc_vis();
    // void citest_gitfile();

    // Compare contents of file `outfname` with the reference file.
    // Any difference = error
    void CompareOutput(strptr outfname);
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_bintests();
    // void citest_checkclean();
    // void citest_lineendings();
    // void citest_shebang();
    // void citest_comptest();
    // void citest_readme();
    void Main();

    // -------------------------------------------------------------------
    // cpp/atf/ci/src.cpp -- source file (cpp/, include/) normalizations including amc
    //

    // indent any source files modified in the last commit
    // indentation under CYGWIN is broken -- and we don't have a cross-platform
    // solution. so only try it on Linux
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_indent_srcfile();

    // indent all script files modified in the last commit
    // void citest_indent_script();

    // update file headers
    // void citest_file_header();

    // source code police
    // void citest_src_lim();

    // run amc
    // void citest_amc();
    // void citest_tempcode();
    // void citest_stray_gen();
    // void citest_encoding();
    // void citest_iffy_src();
    // void citest_non_copyrighted();

    // -------------------------------------------------------------------
    // cpp/atf/ci/ssim.cpp -- ssim database normalizations
    //
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_normalize_acr();
    // void citest_normalize_acr_my();
    // void citest_ssimfile();

    // -------------------------------------------------------------------
    // cpp/atf/ci/ssimfs.cpp
    //

    // check ssimfs rules
    //     (user-implemented function, prototype is in amc-generated header)
    // void citest_ssimfs();
}
