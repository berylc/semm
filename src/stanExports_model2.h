// Generated by rstantools.  Do not edit by hand.

/*
    semm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    semm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with semm.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1
#include <stan/model/model_header.hpp>
namespace model_model2_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_model2");
    reader.add_event(57, 55, "end", "model_model2");
    return reader;
}
#include <stan_meta_header.hpp>
class model_model2 : public prob_grad {
private:
        int K;
        int N;
        int M;
        matrix_d B;
        matrix_d SE;
        vector_d zeros;
public:
    model_model2(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_model2(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_model2_namespace::model_model2";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 1);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "M", "int", context__.to_vec());
            M = int(0);
            vals_i__ = context__.vals_i("M");
            pos__ = 0;
            M = vals_i__[pos__++];
            check_greater_or_equal(function__, "M", M, 1);
            current_statement_begin__ = 6;
            validate_non_negative_index("B", "N", N);
            validate_non_negative_index("B", "M", M);
            context__.validate_dims("data initialization", "B", "matrix_d", context__.to_vec(N,M));
            B = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, M);
            vals_r__ = context__.vals_r("B");
            pos__ = 0;
            size_t B_j_2_max__ = M;
            size_t B_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < B_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < B_j_1_max__; ++j_1__) {
                    B(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 7;
            validate_non_negative_index("SE", "N", N);
            validate_non_negative_index("SE", "M", M);
            context__.validate_dims("data initialization", "SE", "matrix_d", context__.to_vec(N,M));
            SE = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, M);
            vals_r__ = context__.vals_r("SE");
            pos__ = 0;
            size_t SE_j_2_max__ = M;
            size_t SE_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < SE_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < SE_j_1_max__; ++j_1__) {
                    SE(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            // initialize transformed data variables
            current_statement_begin__ = 11;
            validate_non_negative_index("zeros", "M", M);
            zeros = Eigen::Matrix<double, Eigen::Dynamic, 1>(M);
            stan::math::fill(zeros, DUMMY_VAR__);
            // execute transformed data statements
            current_statement_begin__ = 12;
            stan::math::assign(zeros, rep_vector(0, M));
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 17;
            validate_non_negative_index("pi", "K", K);
            num_params_r__ += (K - 1);
            current_statement_begin__ = 18;
            validate_non_negative_index("sigmasq", "4", 4);
            num_params_r__ += 4;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_model2() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 17;
        if (!(context__.contains_r("pi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable pi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("pi");
        pos__ = 0U;
        validate_non_negative_index("pi", "K", K);
        context__.validate_dims("parameter initialization", "pi", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> pi(K);
        size_t pi_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            pi(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.simplex_unconstrain(pi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable pi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 18;
        if (!(context__.contains_r("sigmasq")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigmasq missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigmasq");
        pos__ = 0U;
        validate_non_negative_index("sigmasq", "4", 4);
        context__.validate_dims("parameter initialization", "sigmasq", "vector_d", context__.to_vec(4));
        Eigen::Matrix<double, Eigen::Dynamic, 1> sigmasq(4);
        size_t sigmasq_j_1_max__ = 4;
        for (size_t j_1__ = 0; j_1__ < sigmasq_j_1_max__; ++j_1__) {
            sigmasq(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lb_unconstrain(0, sigmasq);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigmasq: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 17;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> pi;
            (void) pi;  // dummy to suppress unused var warning
            if (jacobian__)
                pi = in__.simplex_constrain(K, lp__);
            else
                pi = in__.simplex_constrain(K);
            current_statement_begin__ = 18;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> sigmasq;
            (void) sigmasq;  // dummy to suppress unused var warning
            if (jacobian__)
                sigmasq = in__.vector_lb_constrain(0, 4, lp__);
            else
                sigmasq = in__.vector_lb_constrain(0, 4);
            // transformed parameters
            current_statement_begin__ = 23;
            validate_non_negative_index("Sigma", "M", M);
            validate_non_negative_index("Sigma", "M", M);
            validate_non_negative_index("Sigma", "K", K);
            std::vector<Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> > Sigma(K, Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic>(M, M));
            stan::math::initialize(Sigma, DUMMY_VAR__);
            stan::math::fill(Sigma, DUMMY_VAR__);
            current_statement_begin__ = 24;
            validate_non_negative_index("a", "2", 2);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> a(2);
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);
            current_statement_begin__ = 25;
            validate_non_negative_index("b", "2", 2);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> b(2);
            stan::math::initialize(b, DUMMY_VAR__);
            stan::math::fill(b, DUMMY_VAR__);
            current_statement_begin__ = 26;
            validate_non_negative_index("c", "2", 2);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> c(2);
            stan::math::initialize(c, DUMMY_VAR__);
            stan::math::fill(c, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 28;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 1, "sigmasq", 1), 
                        "assigning variable a");
            current_statement_begin__ = 29;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        0.0, 
                        "assigning variable a");
            current_statement_begin__ = 30;
            stan::model::assign(b, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        0.0, 
                        "assigning variable b");
            current_statement_begin__ = 31;
            stan::model::assign(b, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 2, "sigmasq", 1), 
                        "assigning variable b");
            current_statement_begin__ = 32;
            stan::model::assign(c, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 3, "sigmasq", 1), 
                        "assigning variable c");
            current_statement_begin__ = 33;
            stan::model::assign(c, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 4, "sigmasq", 1), 
                        "assigning variable c");
            current_statement_begin__ = 35;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        diag_matrix(rep_vector(0, 2)), 
                        "assigning variable Sigma");
            current_statement_begin__ = 36;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        diag_matrix(a), 
                        "assigning variable Sigma");
            current_statement_begin__ = 37;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(3), stan::model::nil_index_list()), 
                        diag_matrix(b), 
                        "assigning variable Sigma");
            current_statement_begin__ = 38;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(4), stan::model::nil_index_list()), 
                        diag_matrix(c), 
                        "assigning variable Sigma");
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 23;
            size_t Sigma_k_0_max__ = K;
            size_t Sigma_j_1_max__ = M;
            size_t Sigma_j_2_max__ = M;
            for (size_t k_0__ = 0; k_0__ < Sigma_k_0_max__; ++k_0__) {
                for (size_t j_1__ = 0; j_1__ < Sigma_j_1_max__; ++j_1__) {
                    for (size_t j_2__ = 0; j_2__ < Sigma_j_2_max__; ++j_2__) {
                        if (stan::math::is_uninitialized(Sigma[k_0__](j_1__, j_2__))) {
                            std::stringstream msg__;
                            msg__ << "Undefined transformed parameter: Sigma" << "[" << k_0__ << "]" << "(" << j_1__ << ", " << j_2__ << ")";
                            stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable Sigma: ") + msg__.str()), current_statement_begin__, prog_reader__());
                        }
                    }
                }
            }
            current_statement_begin__ = 24;
            size_t a_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(a(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: a" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable a: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 25;
            size_t b_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(b(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: b" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable b: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 26;
            size_t c_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < c_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(c(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: c" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable c: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            {
            current_statement_begin__ = 44;
            validate_non_negative_index("ps", "K", K);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> ps(K);
            stan::math::initialize(ps, DUMMY_VAR__);
            stan::math::fill(ps, DUMMY_VAR__);
            current_statement_begin__ = 46;
            lp_accum__.add(inv_gamma_log<propto__>(sigmasq, 1, 1));
            current_statement_begin__ = 47;
            lp_accum__.add(dirichlet_log<propto__>(pi, rep_vector(1, K)));
            current_statement_begin__ = 49;
            for (int n = 1; n <= N; ++n) {
                current_statement_begin__ = 50;
                for (int k = 1; k <= K; ++k) {
                    current_statement_begin__ = 51;
                    stan::model::assign(ps, 
                                stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list()), 
                                (stan::math::log(get_base1(pi, k, "pi", 1)) + multi_normal_log(get_base1(B, n, "B", 1), zeros, add(diag_matrix(to_vector(get_base1(SE, n, "SE", 1))), get_base1(Sigma, k, "Sigma", 1)))), 
                                "assigning variable ps");
                }
                current_statement_begin__ = 53;
                lp_accum__.add(log_sum_exp(ps));
            }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("pi");
        names__.push_back("sigmasq");
        names__.push_back("Sigma");
        names__.push_back("a");
        names__.push_back("b");
        names__.push_back("c");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(4);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(K);
        dims__.push_back(M);
        dims__.push_back(M);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(2);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(2);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(2);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_model2_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> pi = in__.simplex_constrain(K);
        size_t pi_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            vars__.push_back(pi(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> sigmasq = in__.vector_lb_constrain(0, 4);
        size_t sigmasq_j_1_max__ = 4;
        for (size_t j_1__ = 0; j_1__ < sigmasq_j_1_max__; ++j_1__) {
            vars__.push_back(sigmasq(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 23;
            validate_non_negative_index("Sigma", "M", M);
            validate_non_negative_index("Sigma", "M", M);
            validate_non_negative_index("Sigma", "K", K);
            std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> > Sigma(K, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(M, M));
            stan::math::initialize(Sigma, DUMMY_VAR__);
            stan::math::fill(Sigma, DUMMY_VAR__);
            current_statement_begin__ = 24;
            validate_non_negative_index("a", "2", 2);
            Eigen::Matrix<double, Eigen::Dynamic, 1> a(2);
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);
            current_statement_begin__ = 25;
            validate_non_negative_index("b", "2", 2);
            Eigen::Matrix<double, Eigen::Dynamic, 1> b(2);
            stan::math::initialize(b, DUMMY_VAR__);
            stan::math::fill(b, DUMMY_VAR__);
            current_statement_begin__ = 26;
            validate_non_negative_index("c", "2", 2);
            Eigen::Matrix<double, Eigen::Dynamic, 1> c(2);
            stan::math::initialize(c, DUMMY_VAR__);
            stan::math::fill(c, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 28;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 1, "sigmasq", 1), 
                        "assigning variable a");
            current_statement_begin__ = 29;
            stan::model::assign(a, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        0.0, 
                        "assigning variable a");
            current_statement_begin__ = 30;
            stan::model::assign(b, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        0.0, 
                        "assigning variable b");
            current_statement_begin__ = 31;
            stan::model::assign(b, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 2, "sigmasq", 1), 
                        "assigning variable b");
            current_statement_begin__ = 32;
            stan::model::assign(c, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 3, "sigmasq", 1), 
                        "assigning variable c");
            current_statement_begin__ = 33;
            stan::model::assign(c, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        get_base1(sigmasq, 4, "sigmasq", 1), 
                        "assigning variable c");
            current_statement_begin__ = 35;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        diag_matrix(rep_vector(0, 2)), 
                        "assigning variable Sigma");
            current_statement_begin__ = 36;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                        diag_matrix(a), 
                        "assigning variable Sigma");
            current_statement_begin__ = 37;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(3), stan::model::nil_index_list()), 
                        diag_matrix(b), 
                        "assigning variable Sigma");
            current_statement_begin__ = 38;
            stan::model::assign(Sigma, 
                        stan::model::cons_list(stan::model::index_uni(4), stan::model::nil_index_list()), 
                        diag_matrix(c), 
                        "assigning variable Sigma");
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t Sigma_j_2_max__ = M;
                size_t Sigma_j_1_max__ = M;
                size_t Sigma_k_0_max__ = K;
                for (size_t j_2__ = 0; j_2__ < Sigma_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < Sigma_j_1_max__; ++j_1__) {
                        for (size_t k_0__ = 0; k_0__ < Sigma_k_0_max__; ++k_0__) {
                            vars__.push_back(Sigma[k_0__](j_1__, j_2__));
                        }
                    }
                }
                size_t a_j_1_max__ = 2;
                for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                    vars__.push_back(a(j_1__));
                }
                size_t b_j_1_max__ = 2;
                for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
                    vars__.push_back(b(j_1__));
                }
                size_t c_j_1_max__ = 2;
                for (size_t j_1__ = 0; j_1__ < c_j_1_max__; ++j_1__) {
                    vars__.push_back(c(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    static std::string model_name() {
        return "model_model2";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t pi_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t sigmasq_j_1_max__ = 4;
        for (size_t j_1__ = 0; j_1__ < sigmasq_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigmasq" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t Sigma_j_2_max__ = M;
            size_t Sigma_j_1_max__ = M;
            size_t Sigma_k_0_max__ = K;
            for (size_t j_2__ = 0; j_2__ < Sigma_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < Sigma_j_1_max__; ++j_1__) {
                    for (size_t k_0__ = 0; k_0__ < Sigma_k_0_max__; ++k_0__) {
                        param_name_stream__.str(std::string());
                        param_name_stream__ << "Sigma" << '.' << k_0__ + 1 << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                        param_names__.push_back(param_name_stream__.str());
                    }
                }
            }
            size_t a_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "a" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t b_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "b" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t c_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < c_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "c" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t pi_j_1_max__ = (K - 1);
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t sigmasq_j_1_max__ = 4;
        for (size_t j_1__ = 0; j_1__ < sigmasq_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigmasq" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t Sigma_j_2_max__ = M;
            size_t Sigma_j_1_max__ = M;
            size_t Sigma_k_0_max__ = K;
            for (size_t j_2__ = 0; j_2__ < Sigma_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < Sigma_j_1_max__; ++j_1__) {
                    for (size_t k_0__ = 0; k_0__ < Sigma_k_0_max__; ++k_0__) {
                        param_name_stream__.str(std::string());
                        param_name_stream__ << "Sigma" << '.' << k_0__ + 1 << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                        param_names__.push_back(param_name_stream__.str());
                    }
                }
            }
            size_t a_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "a" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t b_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < b_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "b" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t c_j_1_max__ = 2;
            for (size_t j_1__ = 0; j_1__ < c_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "c" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_model2_namespace::model_model2 stan_model;
#endif