#include "exposureconfiguration.h"


ExposureConfiguration::ExposureConfiguration(QObject *parent) : QObject(parent)
{
}

ExposureConfiguration::ExposureConfiguration(ExposureConfiguration const &exposureConfiguration)
    : QObject(exposureConfiguration.parent())
    , m_minimumRiskScore(exposureConfiguration.m_minimumRiskScore)
    , m_attenuationScores(exposureConfiguration.m_attenuationScores)
    , m_daysSinceLastExposureScores(exposureConfiguration.m_daysSinceLastExposureScores)
    , m_durationScores(exposureConfiguration.m_durationScores)
    , m_transmissionRiskScores(exposureConfiguration.m_transmissionRiskScores)
    , m_attenuationWeight(exposureConfiguration.m_attenuationWeight)
    , m_daysSinceLastExposureWeight(exposureConfiguration.m_daysSinceLastExposureWeight)
    , m_durationWeight(exposureConfiguration.m_durationWeight)
    , m_transmissionRiskWeight(exposureConfiguration.m_transmissionRiskWeight)
    , m_durationAtAttenuationThresholds(exposureConfiguration.m_durationAtAttenuationThresholds)
{
}

ExposureConfiguration& ExposureConfiguration::operator=( const ExposureConfiguration &other)
{
    if (this != &other) {
        m_minimumRiskScore = other.m_minimumRiskScore;
        m_attenuationScores = other.m_attenuationScores;
        m_daysSinceLastExposureScores = other.m_daysSinceLastExposureScores;
        m_durationScores = other.m_durationScores;
        m_transmissionRiskScores= other.m_transmissionRiskScores;
        m_attenuationWeight = other.m_attenuationWeight;
        m_daysSinceLastExposureWeight = other.m_daysSinceLastExposureWeight;
        m_durationWeight = other.m_durationWeight;
        m_transmissionRiskWeight = other.m_transmissionRiskWeight;
        m_durationAtAttenuationThresholds = other.m_durationAtAttenuationThresholds;
    }

    return *this;
}

QDBusArgument &operator<<(QDBusArgument &argument, const ExposureConfiguration &exposureConfiguration)
{
    argument.beginStructure();
    argument << exposureConfiguration.minimumRiskScore();
    argument << exposureConfiguration.attenuationScores();
    argument << exposureConfiguration.daysSinceLastExposureScores();
    argument << exposureConfiguration.durationScores();
    argument << exposureConfiguration.transmissionRiskScores();
    argument << exposureConfiguration.attenuationWeight();
    argument << exposureConfiguration.daysSinceLastExposureWeight();
    argument << exposureConfiguration.durationWeight();
    argument << exposureConfiguration.transmissionRiskWeight();
    argument << exposureConfiguration.durationAtAttenuationThresholds();
    argument.endStructure();

    return argument;
}

QDBusArgument const &operator>>(const QDBusArgument &argument, ExposureConfiguration &exposureConfiguration)
{
    quint8 valueInt8;
    QList<quint32> valueUnsignedList;
    double valueDouble;
    QList<qint32> valueSignedList;

    argument.beginStructure();
    argument >> valueInt8;
    exposureConfiguration.setMinimumRiskScore(valueInt8);
    argument >> valueUnsignedList;
    exposureConfiguration.setAttenuationScores(valueUnsignedList);
    argument >> valueUnsignedList;
    exposureConfiguration.setDaysSinceLastExposureScores(valueUnsignedList);
    argument >> valueUnsignedList;
    exposureConfiguration.setDurationScores(valueUnsignedList);
    argument >> valueUnsignedList;
    exposureConfiguration.setTransmissionRiskScores(valueUnsignedList);
    argument >> valueDouble;
    exposureConfiguration.setAttenuationWeight(valueDouble);
    argument >> valueDouble;
    exposureConfiguration.setDaysSinceLastExposureWeight(valueDouble);
    argument >> valueDouble;
    exposureConfiguration.setDurationWeight(valueDouble);
    argument >> valueDouble;
    exposureConfiguration.setTransmissionRiskWeight(valueDouble);
    argument >> valueSignedList;
    exposureConfiguration.setDurationAtAttenuationThresholds(valueSignedList);
    argument.endStructure();

    return argument;
}

quint8 ExposureConfiguration::minimumRiskScore() const
{
    return m_minimumRiskScore;
}

QList<quint32> ExposureConfiguration::attenuationScores() const
{
    return m_attenuationScores;
}

QList<quint32> ExposureConfiguration::daysSinceLastExposureScores() const
{
    return m_daysSinceLastExposureScores;
}

QList<quint32> ExposureConfiguration::durationScores() const
{
    return m_durationScores;
}

QList<quint32> ExposureConfiguration::transmissionRiskScores() const
{
    return m_transmissionRiskScores;
}

double ExposureConfiguration::attenuationWeight() const
{
    return m_attenuationWeight;
}

double ExposureConfiguration::daysSinceLastExposureWeight() const
{
    return m_daysSinceLastExposureWeight;
}

double ExposureConfiguration::durationWeight() const
{
    return m_durationWeight;
}

double ExposureConfiguration::transmissionRiskWeight() const
{
    return m_transmissionRiskWeight;
}

QList<qint32> ExposureConfiguration::durationAtAttenuationThresholds() const
{
    return m_durationAtAttenuationThresholds;
}

void ExposureConfiguration::setMinimumRiskScore(quint8 minimumRiskScore)
{
    if (m_minimumRiskScore != minimumRiskScore) {
        m_minimumRiskScore = minimumRiskScore;
        emit minimumRiskScoreChanged();
    }
}

void ExposureConfiguration::setAttenuationScores(QList<quint32> attenuationScores)
{
    if (m_attenuationScores != attenuationScores) {
        m_attenuationScores = attenuationScores;
        emit attenuationScoresChanged();
    }
}

void ExposureConfiguration::setDaysSinceLastExposureScores(QList<quint32> daysSinceLastExposureScores)
{
    if (m_daysSinceLastExposureScores != daysSinceLastExposureScores) {
        m_daysSinceLastExposureScores = daysSinceLastExposureScores;
        emit daysSinceLastExposureScoresChanged();
    }
}

void ExposureConfiguration::setDurationScores(QList<quint32> durationScores)
{
    if (m_durationScores != durationScores) {
        m_durationScores = durationScores;
        emit durationScoresChanged();
    }
}

void ExposureConfiguration::setTransmissionRiskScores(QList<quint32> transmissionRiskScores)
{
    if (m_transmissionRiskScores != transmissionRiskScores) {
        m_transmissionRiskScores = transmissionRiskScores;
        emit transmissionRiskScoresChanged();
    }
}

void ExposureConfiguration::setAttenuationWeight(double attenuationWeight)
{
    if (m_attenuationWeight != attenuationWeight) {
        m_attenuationWeight = attenuationWeight;
        emit attenuationWeightChanged();
    }
}

void ExposureConfiguration::setDaysSinceLastExposureWeight(double daysSinceLastExposureWeight)
{
    if (m_daysSinceLastExposureWeight != daysSinceLastExposureWeight) {
        m_daysSinceLastExposureWeight = daysSinceLastExposureWeight;
        emit daysSinceLastExposureWeightChanged();
    }
}

void ExposureConfiguration::setDurationWeight(double durationWeight)
{
    if (m_durationWeight != durationWeight) {
        m_durationWeight = durationWeight;
        emit durationWeightChanged();
    }
}

void ExposureConfiguration::setTransmissionRiskWeight(double transmissionRiskWeight)
{
    if (m_transmissionRiskWeight != transmissionRiskWeight) {
        m_transmissionRiskWeight = transmissionRiskWeight;
        emit transmissionRiskWeightChanged();
    }
}

void ExposureConfiguration::setDurationAtAttenuationThresholds(QList<qint32> durationAtAttenuationThresholds)
{
    if (m_durationAtAttenuationThresholds != durationAtAttenuationThresholds) {
        m_durationAtAttenuationThresholds = durationAtAttenuationThresholds;
        emit durationAtAttenuationThresholdsChanged();
    }
}
