from setuptools import setup, Extension

feature_ext = Extension(
    'feature',
    sources=['alpha/feature_wrapper.c']
)

setup(
    name='alpha_features',
    version='0.1',
    packages=['alpha'],
    ext_modules=[feature_ext]
)