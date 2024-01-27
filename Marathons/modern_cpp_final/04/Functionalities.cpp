#include"Functionalities.h"

void CreateObjects(Container& data){
    DeveloperPointer dev1 = std::make_shared<Developer>(
        "Nikko", 
        80000.0f, 
        3, 
        SkillSet::CODING
    );
    DeveloperPointer dev2 = std::make_shared<Developer>(
        "Anshul", 
        90000.0f, 
        6, 
        SkillSet::INTEGRATION_TESTING
    );

    TesterPointer tester1 = std::make_shared<CodeTester>(
        "Rahul", 
        70000.0f, 
        4, 
        SkillSet::CODE_REVIEW
    );
    TesterPointer tester2 = std::make_shared<CodeTester>(
        "Raj", 
        85000.0f, 
        7, 
        SkillSet::UNIT_TESTING
    );

    data["101"] = dev1;
    data["102"] = dev2;
    data["103"] = tester1;
    data["104"] = tester2;
}

Container FindEmployeesWithExperienceBelowSix(const Container& data) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    Container result;
    std::copy_if(data.begin(), data.end(), std::inserter(result, result.begin()), 
                 [](const auto& entry) {
                     const Vtype& employeeVariant = entry.second;

                     bool belowSix = std::visit([](const auto& employee) -> bool {
                         return employee->experienceYears() < 6;
                     }, employeeVariant);

                     return belowSix;
                 });
    return result;
}

float CalculateAverageSalaryOfCodeTesters(const Container& data) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    int count=0;
    float totalSalary = std::accumulate(data.begin(), data.end(), 0.0f,
        [&](float sum, const auto& entry) {
            if (auto tester = std::get_if<TesterPointer>(&entry.second)) {
                count++;
                return sum + (*tester)->salary();
            }
            return sum;
        }
    );
    return (count>0)?(totalSalary/static_cast<float>(count)):0.0f;
}

int CountEmployeesWithSalaryAbove50K(const Container& data) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    return std::count_if(data.begin(), data.end(),
        [](const auto& entry) {
            const Vtype& employeeVariant = entry.second;
            bool above50K = std::visit([](const auto& employee) -> bool {
                return employee->salary() > 50000.0f;
            }, employeeVariant);

            return above50K;
        }
    );
}

std::optional<float> FindSalaryById(const Container& data, const std::string& employeeId) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    auto it = data.find(employeeId);
    if (it != data.end()) {
        const Vtype& employeeVariant = it->second;

        float salary = std::visit([](const auto& employee) -> float {
            if constexpr (std::is_same_v<std::decay_t<decltype(employee)>, DeveloperPointer>) {
                return employee->salary();
            } else if constexpr (std::is_same_v<std::decay_t<decltype(employee)>, TesterPointer>) {
                return employee->salary();
            }
        }, employeeVariant);
        return salary;
    }
    return std::nullopt;
}

bool AllSalariesAbove60000(const Container& data) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    return std::all_of(data.begin(), data.end(),
        [](const auto& entry) {
            const Vtype& employeeVariant = entry.second;

            bool salaryAbove60000 = std::visit([](const auto& employee) -> bool {
                if constexpr (std::is_same_v<std::decay_t<decltype(employee)>, DeveloperPointer>) {
                    return employee->salary() > 60000.0f;
                } else if constexpr (std::is_same_v<std::decay_t<decltype(employee)>, TesterPointer>) {
                    return employee->salary() > 60000.0f;
                }
            }, employeeVariant);
            return salaryAbove60000;
        }
    );
}